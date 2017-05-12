#Bourne shell doesnt have the inbuild arthimetic operations it uses programs like expr or awk

a=10
b=5

echo "Addition of variables"`expr $a  + $b `
echo "Multiplication of variables"`expr $a  \* $b `

#equality of variables

if [ $a == $b ]; then
 echo "Values are equal"
elif [ $a != $b ]; then
   echo "Values are not equal"
fi


