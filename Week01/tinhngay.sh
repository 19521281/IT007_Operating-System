#!/bin/sh
if [ $1 -lt 1900 ]; then
	echo "Nam khong hop le." > $3
elif [ $2 -lt 1 -o $2 -gt 12 ]; then
	echo "Thang khong hop le." > $3
else
	if [ $2 = 1 -o  $2 = 3 -o  $2 = 5 -o  $2 = 7 -o  $2 = 8 -o  $2 = 10 -o  $2 = 12 ]; then
		echo 31 > $3
	elif [ $2 = 4 -o  $2 = 6 -o  $2 = 9 -o  $2 = 11 ]; then
		echo 30 > $3
	else
		if [ $((($1 % 400) == 0)) -eq 1 ] || [ $((($1 % 4) == 0)) -eq 1 -a $((($1 % 100) == 0)) -eq 0 ]; then
			echo 29 > $3
		else
			echo 28 > $3
		fi
	fi
fi
exit 0

