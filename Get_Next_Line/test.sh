if [ "$1" != "-b" ]
then
i=1
while ((i <= 2001))
	do
	echo "BUFFER_SIZE = $i"
	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$i get_next_line.c get_next_line_utils.c main.c
	for doc in 'text1.txt' 'text2.txt' 'text3.txt'
	do
	touch test
	./a.out $doc > test
	diff -u -s $doc test
	rm test
	done
	echo ======================================================================
	((i+=8))
	done
fi
sleep 5
if [ "$1" != "-o" ]
then
	echo BONUS_PART
i=1
while ((i <= 2001))
	do
	echo "BUFFER_SIZE = $i"
	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$i get_next_line_bonus.c get_next_line_utils_bonus.c main.c
	touch test
  	./a.out text1.txt text2.txt text3.txt > test
	diff -u -s text4.txt test
	rm test
	echo ======================================================================
	((i+=8))
	done
fi
