echo "Enter the directory path"
read dirname
cd $dirname
files=$(ls -lS|grep -m 1 "^-")
read -a array <<<$files
echo "Largest File in the directory is : ${array[-1]}"
