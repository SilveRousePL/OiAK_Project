cwrite Do\silu\swypisac\s
read max
cwrite Co\sile\s
read step
cwrite Wypisywanie\sod\s0\sdo\s
vwrite max
cwrite \sco\s
vwrite step
cwrite \s\n

i = 0
while i ! (max+1)
{
	if (i % step) ? 0 {
		vwrite i
		if (i % 15) ? 0
			cwrite \tPodzielne\sprzez\s15
		else skip
		cwrite \n
	}
	else
    		skip
  	i = i + 1
}
