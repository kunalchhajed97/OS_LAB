echo "Enter the full directory name:"
read dirname
OLDIFS=$IFS
IFS=$'\n'
files=($(ls -l1 $dirname | grep "^-"))
IFS=$OLDIFS

for filedata in "${files[@]}"
do
read -a arr <<<"$filedata"
filename="${arr[-1]}"
if grep -q "^$filename" "TOC.txt";
then
	echo "$filename found in TOC.txt"
else
	echo "$filename" >> "TOC.txt"
	echo "$filename added to TOC.txt"
fi
done
