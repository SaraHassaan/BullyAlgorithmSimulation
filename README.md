<h3>Bully Algorithm</h3>
<p>
A bully algorithm is a method used in distributed computing for managing resources and electing a coordinator among a group of nodes. 
The algorithm works by having each node in the system send messages to other nodes to determine if they are still active. If a node fails to respond,
the other nodes will initiate an election process to choose a new coordinator. The node with the highest identifier is typically chosen as the new coordinator.
</p>
<h4>How does a programm work?</h4>
<ul>When the program starts running, press any key to begin.</ul>
<ul>The election messages will then be triggered, displaying 'Election from Process ID (source) to (destination).'</ul>   
<ul>Next, an 'OK' message will be sent to the initiated processes, prompting them to wait for the coordinator message, labeled 'OK from Process ID (source) to (destination).'</ul>
<ul>The coordinator will then send a message to the lower process IDs, marked 'Coordinator from Process ID (source) to (destination).'</ul>  
<ul>Finally, the console will present options to either shut down the current coordinator or bring it back up.</ul>

