#!/usr/bin/env bash

main () {
	if [[ "$1" -lt 1 || "$1" -gt 12 ]]; then
		echo "invalid"
		return 1
	elif [[ "$2" -lt 1 || "$2" -gt 12 ]]; then
		echo "invalid"
		return 1
	fi

	rhyme=(
		"the house that Jack built."
		"the malt that lay in "
		"the rat that ate "
		"the cat that killed "
		"the dog that worried "
		"the cow with the crumpled horn that tossed "
		"the maiden all forlorn that milked "
		"the man all tattered and torn that kissed "
		"the priest all shaven and shorn that married "
		"the rooster that crowed in the morn that woke "
		"the farmer sowing his corn that kept "
		"the horse and the hound and the horn that belonged to "
	)

	for ((i = "$1"; i <= "$2"; i++)); do
		output="This is "
		for ((j = i - 1; j >= 0; j--)); do
			output+="${rhyme[j]}"
		done
		echo "$output"
	done

	return 0
}

main "$@"
