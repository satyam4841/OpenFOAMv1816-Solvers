//- Add a perputation in form of field Ki
{
    forAll(C, cellI)
    {
        double noise = a.value()*Phi[cellI]*(1-Phi[cellI])*(0.5-((double) rand() / (RAND_MAX)));
        double m=(alpha.value()/3.14285)*Foam::atan(gamma.value()*(Te.value()-T[cellI]));
        Ki[cellI]=Phi[cellI]*(1-Phi[cellI])*(Phi[cellI]-0.5+m)+noise;
    }
}
