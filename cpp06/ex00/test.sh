make
RET=$?;
if [ $RET -ne 0 ]; then
	echo	"Makefile failed";
	exit $RET;
fi

runTests ()
{
	for arg in "$@"
    do
		echo $arg
        ./convert $arg
		echo "----------------------------"
    done
}


runTests lorem
runTests c a
runTests 0 -42 42
runTests 332 111 114.2 -155.3 109.00
runTests 0.0f -4.2f 4.2f
runTests -inff +inff nanf
runTests 1.45e+45 1.45e4 445.0e-1