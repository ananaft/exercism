#!/usr/bin/env bash

main () {
	input_length="${#1}"
	result=""
	for ((i = "$input_length" - 1; i >= 0; i--)); do
		result+="${1:i:1}"
	done

	echo "$result"
	return 0
}

main "$@"
