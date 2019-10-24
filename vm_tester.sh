
if [ $# -lt 2 ] || [ $1 == "-help" ] ; then
    echo "usage: sh vm_tester.sh <filename1.cor> <filename2.cor> <filename.etc.cor> <cycles>" ; exit 1
fi

CYCLES=${@: -1}
n=$(($# - 1))
for arg do
  [ "$n" -gt 0 ] && set -- "$@" "$arg"
  shift
  n=$((n - 1))
done

if [ ! -f $1 ]; then
	echo "error: file $1 does not exist" ; exit 1
fi

re='^[0-9]+$'
if ! [[ $CYCLES =~ $re ]]; then
	echo "error: $CYCLES is not a number" >&2 ; exit 1
fi

./corewar $@ -dump $CYCLES | sed -n -e '/^0x/p' > temp_output1
./vm_champs/corewar $@ -d $CYCLES | sed -n -e'/^0x/p' > temp_output2

if cmp -s "temp_output1" "temp_output2"; then
	printf '\033[0;32mmemory is the same at cycle %s\n\033[0m' "$CYCLES"
else
	printf '\033[0;31mmemory is NOT the same at cycle %s\n\033[0m' "$CYCLES"
fi