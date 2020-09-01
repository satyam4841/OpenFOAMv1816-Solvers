Folder Name: Description
	Subfolder name: Description
	Details:
	Notes:
	Possible Errors(PE) + other tips: 


Welding: Contains Solver related to welding process
	
	Case-SolverName: Case folder for various solvers given. 	

	finalv2: Welding solver
		Details: Convective heat transfer boundary condition. Only conductive heat transfer is accounted. Involves phase change. Can simulate any welding path coordinates read from .txt path file. 'Oct10_2.txt' is path file containing coordinates of spiral.

		Notes: Make sure that path co-ordinates lies on the top most surface of mesh i.e if your welding surface in mesh has coordinate Z=0, then the path file coordinates should have Z coordinates slightly below the Z surface and within the first layer of cells like Z={-0.1,0} if cell thickness is 0.1 (basically in first layer of weld surface)
		
		PE:	1. Check the code line 86,101 for appropriate path file source and directory
			2. Check names of defined mesh and path coordinates files.
			3. Change boundary conditions to zero gradient if 'libsGroovy.BC ERROR' appears. Its generally dues to dependancy on Swak4Foam. You can install that and try again but it is not available in newer openfoam versions +18.06 as of year 2020.
			4. Line 148 defines heat source model. Use 'source.h' and 'guassianSource.h' for Goladk's-DE and guassian surface heat source model resply. Appropriate changes needs to be made in Transport properties when changing heat source type.
			5. Using std namecase in solver(rectToPolar.h) might invoke some errors depending on the openfoam and g++ version 

	pcheck2: To validate the path of welding without running the whole simulation. 
		Details: Simply highlights all the cells in mesh that comes in the path of the simulation. Use this solver to check the welding trajectory and if the coordinates are as per requirement. Once the welding path is validated then proceed to finalv2 solver.
		
		Notes: Similar to finalv2

	multiRegionWeld: Welding solver with contact resistance between workpiece and backing plate
		Details: Similar to finalv2 but involves multiple region so regions like workpiece, backing plate with different material properties and contact resistance can be defined.
		
		Notes: Similar to finalv2, Numerical instabilities originates hence need to try mesh with various degree of coarseness and cells.

