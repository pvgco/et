opt=1 # to get option
while [ "$opt" -lt 6 ]
do
echo -e "\n\nEnter option\n1.Create Adress Book\n2.View Address Book\n3.Insert Record in Book\n4.Delete a Record\n5.Modify a Record\nEnter option :"
read opt 
case $opt in

1)
cont=1
echo "Enter File Name"
read fileName
if [ -e $fileName ] ; then
rm $fileName
fi
echo -e "Roll No. NAME\tCity\tPHONE NUMBER\n--------------------------------------\n" | cat >> $fileName
while [ $cont -gt 0 ]
do
echo "Enter Roll Number ; "
read roll
echo "Enter Name : "
read name
echo "Enter City of $name"
read city
echo "Enter phone number of $name"
read phone
echo -e "$roll\t $name\t $city\t$phone" | cat >> $fileName
echo "Enter 0 to Stop, 1 to Enter next"
read cont
done
;;

2)
cat $fileName
;;

3)
echo "To Insert Record\nEnter Roll Number ; "
read roll
echo "Enter Name : "
read name
echo "Enter City of $name"
read city
echo "Enter phone number of $name"
read phone
echo -e "$roll\t $name\t $city\t$phone" | cat >> $fileName
;;

4)
echo "Delete record\nRoll Number : "
read no
temp="temp"
grep -v $no $fileName | cat >> $temp
rm $fileName
cp $temp $fileName
rm $temp
;;

5)
echo "Modify record\nEnter Roll number :"
read no
temp="temp"
grep -v $no $fileName | cat >> $temp
rm $fileName
cp $temp $fileName
rm $temp
echo "Enter Name"
read name
echo "Enter City of $name"
read city
echo "Enter phone number of $name"
read phone
echo -e "$roll\t $name\t $city\t$phone" | cat >> $fileName
;;
esac
done
