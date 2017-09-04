read -r -a arr1 <<<"$(cat 'num1.txt')"
read -r -a arr2 <<<"$(cat 'num2.txt')"
declare -a arr3
i=0;j=0;k=0
while [[ ${arr1[$i]} != "" && ${arr2[$j]} != "" ]]
do
	if [ ${arr1[$i]} -lt ${arr2[$j]} ]
	then
		arr3[$k]=${arr1[$i]}
		i=$((i+1))
	else
		arr3[$k]=${arr2[$j]}
		j=$((j+1)) 
	fi
	k=$((k+1))
done
while [[ ${arr1[$i]} != "" ]]; do
	arr3[$k]=${arr1[$i]}
	i=$((i+1))
	k=$((k+1))
done
while [[ ${arr2[$j]} != "" ]]; do
	arr3[$k]=${arr2[$j]}
	j=$((j+1))
	k=$((k+1))
done
echo "${arr3[*]}"
