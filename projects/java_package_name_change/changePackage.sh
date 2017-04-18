#/bin/bash

declare OLDDIR
declare NEWDIR

if [ $# -lt 2 ] || [ $# -gt 3 ]
then
	>&2  echo "usage: changePackage.sh [flags] <old-package> <new-package>"
	exit 1
fi

if [ $# -eq 3 ]
then
	OLDNAME=$2
	NEWNAME=$3
	if [ $1 != "-d" ]
	then
		>&2 echo "usage: changePackage.sh [flags] <old-package> <new-package>"
		exit 1
	fi
else
	OLDNAME=$1
	NEWNAME=$2
fi

checkName (){
	TMP=$1
	COUNT=0
	IFS='.' read -ra NAME <<< "$TMP"
	
	for i in "${NAME[@]}";
	do	
		if [[ $i = *[![:ascii:]]* ]]  
		then
			return 1 #false
		else
			let "COUNT = COUNT + 1"
		fi
	done
		
	for (( i=1; i<${#TMP}; i++ )); do
		if [[ "${TMP:$i:1}" = "-" ]] #|| [[ "$OLDNAME" =~ \ |\' ]] || [[ "$NEWNAME" =~ \ |\' ]]

		then
			return 1 #false		
		fi
	done
	echo "${TMP:0:1}" | grep [0-9] > /dev/null
	if [ $? -eq 0 ] 
	then
	{
		
		return 1 #false
	}
	fi
	
	#if [ $COUNT -ge 2 ]
	#then
	#	return 0 #true
	#else
	#	return 1 #false
	#fi
}


verifyDirectory() { #1st arg - old package name
	firstWord=0 #just a boolean to make sure we grab only the package name
	TMP=$1
	IFS='.' read -ra NAME <<< "$TMP"

	for i in "${NAME[@]}";
	do	
		if [[ $firstWord -eq 0 ]] 
		then
			packageFolder=$i
		fi
		firstWord=1
	done

	if [ ! -d "$packageFolder" ]; then
		>&2 echo ERROR: package does not exist: $1
		exit 3
	fi
OLDDIR=$packageFolder
}

directoryPossible (){ #1st args - new package name
	firstWord=0 #just a boolean to make sure we grab only the package name
	TMP=$1
	IFS='.' read -ra NAME <<< "$TMP"

	for i in "${NAME[@]}";
	do	
		if [[ $firstWord -eq 0 ]] 
		then
			newFolder=$i
		fi
		firstWord=1
	done
	$(mkdir $newFolder 2> /dev/null)
	#STRING=$(echo $NEWNAME | tr '.' '/')
	if [ $? -gt 0 ]
	then
		
		STRING=$(echo $NEWNAME | tr '.' '/')
		>&2 echo ERROR: unable to create directory: $STRING
		exit 4  
	fi	
		
NEWDIR=$newFolder
}

copyPackageFiles (){ #1st arg - old name, 2nd arg - new name
	for d in $(find $1 -type f -name "$1.*");
	do
		$( cp -r "$d" "$2" )	
	done
	
	cd "$2"	
	for d in $(ls);
	do	
			
		STRING=$( echo $d | cut -d'.' -f2,3,4,5,6,7,8,9,10 )	
		$( mv "$d" "$2.$STRING" )
		echo "$d renamed to $2.$STRING"				
	done
	cd ".."
}
changeName (){
	
	#need new directory
	for d in $(find $1 -type f );
	do		
		LINE=$( cat $d | grep -e package -n 2> /dev/null ) #| cut -d':' -f1 )
		if [ $? -gt 0 ] || [ "$d" = "sub1*" ]
		then
			>&2 echo "ERROR: invalid Java source file: $d" 
			exit 5
		else	
			LINENUMBER=$( echo $LINE | cut -d':' -f1 )
			$( sed -i "$LINENUMBER"'s/.*/package '"$NEWNAME"'/' "$d" )
		fi
	done
	
}

directoryPossible $NEWNAME
checkName $OLDNAME
OLDOUTPUT=$?
checkName $NEWNAME
NEWOUTPUT=$?

if [ $OLDOUTPUT -eq 1 ] || [[ "$OLDNAME" =~ \ |\' ]] 
then
	#old output WRONG bub
	>&2 echo "ERROR: invalid package name: $OLDNAME"
	exit 2
else	
	if [ $NEWOUTPUT -eq 1 ] || [[ "$NEWNAME" =~ \ |\' ]] 
	then
		#new output WRONG bub
		>&2 echo "ERROR: invalid package name: $NEWNAME"
		exit 2
	fi
fi

verifyDirectory $OLDNAME
#directoryPossible $NEWNAME
copyPackageFiles $OLDDIR $NEWDIR
changeName $NEWDIR

if [ "$1" = "-d" ]
then
	$(rm -rf "$OLDDIR")
	if [ $? != 0 ]
	then
		echo "unable to remove directory: $OLDDIR"
	fi

fi
exit 0;
