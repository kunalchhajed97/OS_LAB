echo "Enter the directory path"
read dirname
cd $dirname
files=$(ls -ltr|grep -m 1 "^-")
read -a array <<<$files
echo "Removing file : ${array[-1]}"
rm ${array[-1]}
echo "Removed file : ${array[-1]}"
