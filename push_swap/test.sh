while true
do
	ARG="`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`"
	./push_swap $ARG | ./checker $ARG
	./push_swap $ARG | wc -l
	sleep 0.2
done