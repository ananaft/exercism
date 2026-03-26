return {
  value = function(colors)
	  local result = ''
	  for i = 1, #colors  do
		  if i > 2 then
			  break
		  elseif colors[i] == 'black' then
			  result = result .. '0'
		  elseif colors[i] == 'brown' then
			  result = result .. '1'
		  elseif colors[i] == 'red' then
			  result = result .. '2'
		  elseif  colors[i] == 'orange' then
			  result = result .. '3'
		  elseif colors[i] == 'yellow' then
			  result = result .. '4'
		  elseif colors[i] == 'green' then
			  result = result .. '5'
		  elseif colors[i] == 'blue' then
			  result = result .. '6'
		  elseif colors[i] == 'violet' then
			  result = result .. '7'
		  elseif colors[i] == 'grey' then
			  result = result .. '8'
		  elseif colors[i] == 'white' then
			  result = result .. '9'
		  end
	  end
	  return tonumber(result)
  end
}
