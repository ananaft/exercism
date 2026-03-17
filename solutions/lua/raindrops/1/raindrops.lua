return function(n)
	local message = ""
	if n % 3 == 0 then
		message = message .. "Pling"
	end
	if n % 5 == 0 then
		message = message .. "Plang"
	end
	if n % 7 == 0 then
		message = message .. "Plong"
	end
	if message == "" then
		return tostring(n)
	else
		return message
	end
end
