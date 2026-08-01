#!/usr/bin/env bash

main () {
	local scores=(
		eggs
		peanuts
		shellfish
		strawberries
		tomatoes
		chocolate
		pollen
		cats
	)

	case "$2" in
		allergic_to)
			local allergy
			for i in "${!scores[@]}"; do
				if [[ "$3" == "${scores[i]}" ]]; then
					allergy=$(( 1 << $i ))
					break
				fi
			done
			if (( $1 & $allergy )); then
				echo 'true'
			else
				echo 'false'
			fi
			exit 0
			;;
		list)
			local allergies=()
			for i in "${!scores[@]}"; do 
				if (( $1 & (1 << $i) )); then
					allergies+=( "${scores[i]}" )
				fi
			done
			echo "${allergies[@]}"
			exit 0
			;;
		*)
			echo "Unknown value: $2" >&2
			exit 1
			;;
	esac
}

main "$@"
