
    scalar initialResidual = 0;
    int iCorr=0;
    int reg = 0;
    volVectorField C = solidRegions[reg].C();  //solidRegion[weldRegion]
    double deltaTime=runTime.deltaT().value();
    double totalTime=50;//runTime.endTime().value();
    double totalSteps=totalTime/deltaTime;
    int flagCell=0;

    Info<< "Time of simulation = " << totalTime <<"s"<<nl << endl;
    Info<< "Total timesteps: = " << totalSteps << nl << endl;
    
//**************  READING SPIRAL COORDINATES FROM FILE *****************//   
        int nline=0;
        std::string line;        
        std::ifstream myfile;
        myfile.open("/home/satyam/SpiralData/spiraldatapolar.txt");
        if(myfile.is_open())
        {
            while(!myfile.eof())
            {
                getline(myfile,line);
                nline++;
            }
            myfile.close();
        }

        cout<<"number of coordinates :"<<nline<<"\n";    
        std::vector<Cartesian> spiral(nline); 
        int t=0;
        std::fstream inputfile;
        inputfile.open("/home/satyam/SpiralData/spiraldatapolar.txt");
        while(!inputfile.eof())
        {
            inputfile>>spiral[t].x>>spiral[t].y;
            spiral[t].z=0.05;
            t++;
        }
        inputfile.close();

//**************  FINDING THE CELL ID's CONTAINING SPIRAL COORDINATES *****************//   
        Info<< "Before scanning for cell in region: " << solidRegions[reg].name() << nl << endl;

        std::vector<int> cellii(nline);
        for (int t=0;t<nline;t++)
        {
            vector position(spiral[t].x, spiral[t].y, -0.0001);
            cellii[t] = solidRegions[reg].findCell(position);
        }

//*******************  KEEPING ONLY UNIQUE CELLID'S OF THE SPIRAL PATH  *********************//         
        std::vector<int> spiralcells;
        for (int i=1;i<cellii.size();i++)
        {
            if ((cellii[i-1]!=cellii[i]) || i==1)
            {
                    spiralcells.push_back(cellii[i]);
            }
        }
        //PRINTS TOTAL NUMBER CELL TO MAKE SPIRAL   
        Info<< "Total input:" << cellii.size() <<"\t" << "Unique: " << spiralcells.size() << nl << endl;
        int spiCell=spiralcells.size();
        int duration=totalSteps/spiCell;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

    Info<< "\nCalculating temperature distribution\n" << endl;
    
    Info<< "Duration at each cell:"<< duration << endl;
