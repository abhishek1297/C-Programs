'''
Abhishek Purandare
446
Water-Jug Problem.
'''
from copy import deepcopy
from itertools import permutations

class State : 
	def __init__(self, jugs, seq, parent_seq, rule, M, N) :
		self.seq = seq #id
		self.parent_seq = parent_seq # parent id
		self.jugs = jugs # jug's current values
		self.rule = rule # rule applied to reach the state
		self.M = M # first jug capacity
		self.N = N # second jug capacity


print "\nEnter The jug capacities :",
jugs_cap = map(int, raw_input().split())
no_of_jugs = len(jugs_cap)

print "Enter Target :", 
target = int(raw_input())
bfs_queue = [State([0] * no_of_jugs, 0, -1, 0, -1, -1)] # traversal
visited_states = [] # to avoid repititions
output_path = [] # to display path

print "\nInitial State -> ", [0] * no_of_jugs
print "Goal State -> Any one of the jug must have %d-gallons of water.\n"%target 

# production rules
def fill_jug(index, jugs) :
	if jugs[index] < jugs_cap[index] :
		jugs[index] = jugs_cap[index]
		return jugs, jugs_cap[index], 1
	return None, -1, -1
		
	
def empty_jug(index, jugs) :
	if jugs[index] > 0 :
		jugs[index] = 0
		return jugs, jugs_cap[index], 2
	return None, -1, -1
	
def pour_N_to_M(M, N, jugs) :
	if jugs[M] + jugs[N] >= jugs_cap[M] and jugs[N] > 0 :
		jugs[N] -= jugs_cap[M] - jugs[M]
		jugs[M] = jugs_cap[M]
		return jugs, jugs_cap[M], jugs_cap[N], 3
	return None, -1, -1, -1

def pour_all_N_to_M(M, N, jugs) :
	if jugs[M] + jugs[N] <= jugs_cap[M] and jugs[N] > 0 :
		jugs[M] += jugs[N]
		jugs[N] = 0
		return jugs, jugs_cap[M], jugs_cap[N], 4
	return None, -1, -1, -1
	
def success(state) :
	for i in state.jugs :
		if i == target :
			return True
	return False
#-----------------------------
	
def state_visited(state) :
	for st in visited_states :
		if cmp(st.jugs, state.jugs) == 0 :
			return True
	return False

if __name__ == "__main__" :	
	
	# function lists
	rules_1 = [fill_jug, empty_jug] 
	rules_2 = [pour_N_to_M, pour_all_N_to_M]
	seq = 1 # Node identifier
	done = False
	# approach using breadth first search
	while bfs_queue :
		current_state = bfs_queue.pop(0)
		visited_states.append(current_state)
		for func in rules_1 : 
			for i in range(no_of_jugs) :
				temp_jugs = deepcopy(current_state.jugs)
				# applying rules 1 & 2
				temp_jugs, jug_cap, rule_no = func(i, temp_jugs) 
				if rule_no == -1 :
					continue
				state = State(temp_jugs, seq, current_state.seq, rule_no, jug_cap, -1)
				seq += 1
				if success(state) :
					done = True
					visited_states.append(state)
					break
				if not state_visited(state) :
					bfs_queue.append(state)
			if done :
				break
		if done :
			print "GOAL reached!\n"
			break
			
		# all the permutations of indices of the 2 jugs involved
		perms = list(permutations(range(no_of_jugs), 2))
		for func in rules_2 :
			for index in perms :
				temp_jugs = deepcopy(current_state.jugs)
				# applying rules 3 & 4
				temp_jugs, jug1_cap, jug2_cap, rule_no = func(index[0], index[1], temp_jugs) 
				if rule_no == -1 :
					continue
				state = State(temp_jugs, seq, current_state.seq, rule_no, jug1_cap, jug2_cap)
				seq += 1
				if success(state) :
					done = True
					visited_states.append(state)
					break
				if not state_visited(state) :
					bfs_queue.append(state)
			if done :
				break
		if done :
			print "GOAL reached!\n"
			break
			
	if not done :
		print "NO SOLUTION!\n"
		exit(1)
		
	output_path.append(visited_states[-1]) # goal state
	parent_seq = output_path[0].parent_seq
	while parent_seq != -1 :
		for st in visited_states :
			if st.seq == parent_seq :
				parent_seq = st.parent_seq
				output_path.append(st)
				break
	
	rev = list(reversed(output_path))[1:]
	print [0] * no_of_jugs, " <- Initial State."
	for st in rev :
		print st.jugs,
		if st.N == -1 :
			if st.rule == 1 :
				print " <- 1. Fill %d-gallon jug."%(st.M)
			else :
				print " <- 2. Empty %d-gallon jug."%(st.M)
		else :
			if st.rule == 3 :
				print " <- 3. Pour water from %d-gallon to %d-gallon jug."%(st.N, st.M)
			else :
				print " <- 4. Pour all the water from %d-gallon to %d-gallon jug."%(st.N, st.M)
				
	print "\nDone.\n"