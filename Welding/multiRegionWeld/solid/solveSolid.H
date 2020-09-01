if (finalIter)
{
    mesh.data::add("finalIteration", true);
}

{
    for (int nonOrth=0; nonOrth<=nNonOrthCorr; ++nonOrth)
    {
        int iCorr = 0;
	        do
	        {   
	            //#include "resetH.H"
	            fvScalarMatrix TEqn
	            (
	               	fvm::ddt(T) - fvm::laplacian(thermo.alpha()/rho, T) + (LHF/cp)*fvc::ddt(FL) + (LHV/cp)*fvc::ddt(FV)  
	           	 ==
	               	fvOptions(T) + g
	           	);			
	         
	            fvOptions.constrain(TEqn);
	            initialResidual = TEqn.solve().max().initialResidual();
	            fvOptions.correct(T);
	            volScalarField FLNew = FL + FLrelax*(T-((TL-TS)*FL+TS))*Cp/LHF;
	            FL = max(scalar(0), min(FLNew, scalar(1))); 
	            volScalarField FVNew = FV + FVrelax*(T-((BT-BS)*FV+BS))*Cp/LHV;
	            FV = max(scalar(0), min(FVNew, scalar(1)));
		} while (initialResidual > 1e-05 && ++iCorr < 500);
        
    }

    thermo.correct();

    Info<< "Min/max T:" << min(thermo.T()).value() << ' '
        << max(thermo.T()).value() << endl;
}

if (finalIter)
{
    mesh.data::remove("finalIteration");
}
