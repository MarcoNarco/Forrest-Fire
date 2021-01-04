
Your program must provide the following functionality and adhere to the following constraints:

 Allow the user to input the file describing the initial condition of the forest
 	Do NOT hardcode the filename into your program
	The first line will specify how many days a tree burns for
	All other lines will be comma delimited containing the following characters:
 ‘T’ is a tree that is not on fire
 ‘F’ is a tree that is on fire
 ‘B’ is a tree that has already burnt down
 ‘‘is an empty patch of land
	The forest can be any sized rectangle
	Assume the top of the grid is North
 Allow the user to input the file describing the weather forecast
	Do NOT hardcode the filename into your program o Each line will specify the weather for that day:
 ‘N’ indicates the wind is blowing to the North
 ‘S’ indicates the wind is blowing to the South
 ‘W’ indicates the wind is blowing to the West
 ‘E’ indicates the wind is blowing to the East
 ‘R’ indicates that it is raining and there is no wind blowing
	If the weather is not specified for a day, then assume it is the same as the previous day
	The weather will always be specified for Day 0

 Once initialized, your system should simulate the forest fire in the following way:
		The initial condition of the forest, as specified in the file, represents Day 0 of the fire, and should be output in a grid format
During every day in which there is at least one tree still on fire:
 The weather should first be checked for that day, if it changed the user should be notified of the
	change
 If it is not raining, then the fire should spread according to the direction of the wind. For
	example, if the wind is blowing to the South, then the fire can only spread to trees south of it:

Similarly, if the wind is blowing to the North, then the fire can only spread to trees north of it, and so on for West and East
 If it is raining, then no wind is blowing and the fire cannot spread that day
 A tree can only set other trees on fire the day after it was set on fire
 After a tree has burned for the specified number of days, it becomes a ‘B’ representing a burnt
  down tree. Day 0 does count as a day for a tree burning
 Finally, the current condition of the forest should be output in a grid format, along with its day number.
	 Once there are no trees on fire, the simulation should halt, output the final condition of the forest, and specify how many days the fire took to burn. Day 0 should be included in this count, but the first day with no fires should not.
