#!/bin/bash
# tetris written in bash
# need to get UI
# a rect in the center of the screen

#blocks
# we use utf 8 character '\u25fc' to display blocks

BLOCK=$'\xE2\x97\xBC\x0A\x04'
#O tetrimino
declare -a O
O[0]=$BLOCK
O[1]=$BLOCK
O[2]='\n'
O[3]=$BLOCK
O[4]=$BLOCK

#this helps print the block nice
O_string=${O[0]}${O[1]}${O[2]}${O[3]}${O[4]}




declare -a DISPLAY
init_display ()
{
	IFS=$'\n' #allows white space to be printed
		
	for i in `seq 0 219`;
	do
		var=$(expr $i % 11)
		if [ $var -eq 0 ]
		then
			DISPLAY[$i]=$"\n"
		else
			DISPLAY[$i]=$"-"
		fi
	done

	#echo -e ${DISPLAY[@]}

}
 
#use sleep command for delay
	

init_display
echo -e $O_string 

#echo -ne ${DISPLAY[@]}

#sleep 1

#DISPLAY[24]=$BLOCK

#echo
#echo
#echo -ne ${DISPLAY[@]}$'\r'
X=15
Y=16
A=5
B=4
blu=0

refresh_board()
{
	
	DISPLAY[$X]='-'
	DISPLAY[$Y]='-'
	DISPLAY[$A]='-'
	DISPLAY[$B]='-'

}

run_game2()
{
	for i in {0..219} ; do
		printf ${DISPLAY[$i]}
	done
	refresh_board
	X=$(($X+11)) 
	Y=$(($Y+11)) 
	A=$(($A+11)) 
	B=$(($B+11)) 
	DISPLAY[$X]=$BLOCK
	DISPLAY[$Y]=$BLOCK
	DISPLAY[$A]=$BLOCK
	DISPLAY[$B]=$BLOCK
	printf " \e[21A\n"
	sleep 1
}

dad=1
move_piece()
{
	while [ 5 ]; 
	do
		case "$ui" in
		$'\x1b') #Handle esc sequence.
	    	#flush read. We account for sequences for Fx keys as 
	    	#well. 6 shoud suffice for more then enough.
	    		read -rsn1 -t 1 tmp
	    		if [[ "$tmp" == "[" ]]; then
	    			read -rsn1 -t 1 tmp
				case "$tmp" in
				"C") X=$(($X+1))
				     Y=$(($Y+1))
				     printf "hey\n"
				     dad=0
				 
				esac
	   		 fi
	    		#flush stdin with 0.1 sec timeout
	    		#read -rsn5 -t 1
	    		;;
		q) break;;
		esac
		run_game2
	done
}


run_game()
{
	#read -sn1 esc
	#read -sn1 -t 0.001 bra # "-t 0.001" is for robust-ness so pressing just any key wont put it into the wrong "read"
	#read -sn1 -t 0.001 typ
	#if [ "$esc$bra$typ" == $'\033'[A ]; then
	#    echo "You pressed the UP arrow."
	#    else
	#        echo "You didn't press the up arrow, did you?"
	#	fi
	for j in {1..10}; do
		#read is here but its weird responsibely
		#need to fix way tetris board is set up
		#need to make this more responsive 
		read -s -t 1 -n 1 key
		case "$key" in 
		d) X=$(($X+1))
		   Y=$(($Y+1))
		   A=$(($A+1))
		   B=$(($B+1));;
		
		esac

		for i in {0..219} ; do
			printf ${DISPLAY[$i]}
		done
		#make a refresh function for this
		#move_piece
		refresh_board 
	X=$(($X+11)) 
	Y=$(($Y+11)) 
	A=$(($A+11)) 
	B=$(($B+11)) 
	#Make an increment block function
	DISPLAY[$X]=$BLOCK
	DISPLAY[$Y]=$BLOCK
	DISPLAY[$A]=$BLOCK
	DISPLAY[$B]=$BLOCK
	printf " \e[21A\n"
	sleep 1
	done
}


run_game  
#move_piece 
