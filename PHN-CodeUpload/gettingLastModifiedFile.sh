latestfile=$(ls -lrt *.{cpp} myPath/ c| tail -1);
parsefile=$( echo $latestfile | awk ' { print $(NF) } ' ) ;
clear

echo $parsefile;
