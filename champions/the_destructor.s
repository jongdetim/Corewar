.name		"the destructor"
.comment	"A lesson of how to be a man"

# Anna's champ attempt

fork_it:
	fork	%:clone_it

live_it:
	st		r1, 6
	live	%42

clone_it:
	ld		%1, r2 #load live opcode to r2
	st		r2, 64 #set live opcode after 64 bytes
	st		r1, 63 #set player id after live opcode
