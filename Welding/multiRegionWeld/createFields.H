#include "createFluidFields.H"
#include "createSolidFields.H"

volScalarField g
(
    IOobject
    (
        "g",
        runTime.timeName(),
        solidRegions[0],
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    solidRegions[0]
);

volScalarField FL
(
    IOobject
    (
        "FL",
        runTime.timeName(),
        solidRegions[0],
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    solidRegions[0],
    dimless
);

volScalarField FV
(
    IOobject
    (
        "FV",
        runTime.timeName(),
        solidRegions[0],
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    solidRegions[0],
    dimless
);

Info<< "Reading transportProperties\n" << endl;

IOdictionary transportProperties
(
    IOobject
    (
        "transportProperties",
        runTime.constant(),
        solidRegions[0],
        IOobject::MUST_READ_IF_MODIFIED,
        IOobject::NO_WRITE
    )
);

//Info<< "Reading rho: \n" << endl;

//MATERIAL PROPERTY

dimensionedScalar rho
(
    "rho",
    dimDensity,
    transportProperties.lookup("rho")
);

dimensionedScalar Cp
(
    "Cp",
    dimEnergy/(dimMass*dimTemperature),
    transportProperties.lookup("Cp")
);

dimensionedScalar LHV
(
    "LHV",
    dimEnergy/dimMass,
    transportProperties.lookup("LHV")
);

dimensionedScalar LHF
(
    "LHF",
    dimEnergy/dimMass,
    transportProperties.lookup("LHF")
);

dimensionedScalar TS
(
    "TS",
    dimTemperature,
    transportProperties
);
dimensionedScalar TL
(
    "TL",
    dimTemperature,
    transportProperties
);
dimensionedScalar BS
(
    "BS",
    dimTemperature,
    transportProperties
);
dimensionedScalar BT
(
    "BT",
    dimTemperature,
    transportProperties
);

// Info<< "Reading diffusivity DT\n" << endl;

// dimensionedScalar DT
// (
//     "DT",
//     dimArea/dimTime,
//     transportProperties.lookup("DT")
// );

dimensionedScalar FLrelax
(
    "FLrelax",
    dimless,
    transportProperties.lookup("FLrelax")
);

dimensionedScalar FVrelax
(
    "FVrelax",
    dimless,
    transportProperties.lookup("FVrelax")
);

// HEAT SOURCE PARAMETERS
dimensionedScalar a
(
    "a",
    dimLength,
    transportProperties.lookup("a")
);

dimensionedScalar b
(
    "b",
    dimLength,
    transportProperties.lookup("b")
);

dimensionedScalar cf
(
    "cf",
    dimLength,
    transportProperties.lookup("cf")
);

dimensionedScalar cr
(
    "cr",
    dimLength,
    transportProperties.lookup("cr")
);

dimensionedScalar ff
(
    "ff",
    dimless,
    transportProperties.lookup("ff")
);

dimensionedScalar fr
(
    "fr",
    dimless,
    transportProperties.lookup("fr")
);

dimensionedScalar q
(
    "q",
    dimEnergy/dimTime,
    transportProperties.lookup("q")
);

dimensionedScalar r
(
    "r",
    dimLength,
    transportProperties.lookup("r")
);

// const dictionary& tempControl = mesh.solutionDict().subDict("tempAnalysis");
// int nTempCorr = tempControl.lookupOrDefault<int>("nCorrectors", 0);
// scalar convergenceTempTolerance(readScalar(tempControl.lookup("T")));


//#include "createFvOptions.H"
