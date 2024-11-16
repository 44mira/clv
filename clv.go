package main

import (
	"embed"
	"fmt"
	"log"
	"os"
	"path/filepath"
)

//go:embed src/*
var src embed.FS

func writeFile(path, content string) error {
	os.MkdirAll(filepath.Dir(path), os.ModePerm)
	return os.WriteFile(path, []byte(content), 0644)
}

// [[ createTestDir ]] {{{
func createTestDir() error {
	testsDir := "tests"
	if len(os.Args) == 3 {
		testsDir = os.Args[2]
	}

	files := []string{"src/clv.c", "src/clv.h", "src/clv_internals.h"}

	for _, file := range files {
		content, err := src.ReadFile(file)
		if err != nil {
			return err
		}

		target := filepath.Join(testsDir, filepath.Base(file))

		err = writeFile(target, string(content))
		if err != nil {
			return err
		}
	}

	content, err := src.ReadFile("src/Makefile")
	if err != nil {
		return err
	}

	err = writeFile("Makefile", string(content))
	if err != nil {
		return err
	}

	return nil
}

// }}}

// [[ createTests ]] {{{
func createTests() error {
	template, err := src.ReadFile("src/template.c")
	if err != nil {

		return err
	}

	for i := 2; i < len(os.Args); i++ {
		target := filepath.Join("tests", os.Args[i])

		err = writeFile(target+"_test.c", string(template))
		if err != nil {
			return err
		}
	}

	return nil
}

// }}}

// [[ displayHelp ]] {{{
func displayHelp() {
	fmt.Printf(`
c'est la vie

clv init [tests directory]                  -- initialize the tests directory (defaults to 'tests/')
clv help                                    -- display this menu
clv create <test_name> [ ... <test_name> ]  -- create a test template
`)
}

// }}}

func main() {
	if len(os.Args) == 1 {
		displayHelp()
		return
	}

	switch os.Args[1] {
	case "init":
		err := createTestDir()
		if err != nil {
			log.Fatalf("An error has occurred in creating the tests directory: %v\n", err.Error())
		}

		fmt.Println("The tests directory has been created.")
	case "create":
		if len(os.Args) < 3 {
			log.Fatalln("Please provide the test name(s).")
		}

		err := createTests()
		if err != nil {
			log.Fatalf("An error has occurred in creating the test template(s): %v\n", err.Error())
		}
		fmt.Println("The tests have been created.")
	case "help":
		displayHelp()
	default:
		displayHelp()
	}
}
