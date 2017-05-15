
cur_date=$(date);
cur_date=${cur_date//[[:space:]]/_}
cp ./$1 ./$1"_"$cur_date

