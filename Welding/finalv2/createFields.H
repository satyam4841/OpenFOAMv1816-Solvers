Info<< "Reading field T\n" << endl;

volScalarField T
(
    IOobject
    (
        "T",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

volScalarField DT
(
    IOobject
    (
        "DT",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::NO_WRITE
    ),
    mesh
);

Info<< "Reading field heat source (g)\n" << endl;

volScalarField g
(
    IOobject
    (
        "g",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

volScalarField FL
(
    IOobject
    (
        "FL",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimless
);

volScalarField FV
(
    IOobject
    (
        "FV",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimless
);



Info<< "Reading transportProperties\n" << endl;

IOdictionary transportProperties
(
    IOobject
    (
        "transportProperties",
        runTime.constant(),
        mesh,
        IOobject::MUST_READ_IF_MODIFIED,
        IOobject::NO_WRITE
    )
);

//Info<< "Reading rho: \n" << endl;

//MATERIAL PROPERTY
dimensionedScalar weldtime
(
    "weldtime",
    dimTime,
    transportProperties.lookup("weldtime")
);

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

Info<< "Reading diffusivity DT\n" << endl;

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

const dictionary& tempControl = mesh.solutionDict().subDict("tempAnalysis");
int nTempCorr = tempControl.lookupOrDefault<int>("nCorrectors", 1);
scalar convergenceTempTolerance(readScalar(tempControl.lookup("T")));


#include "createFvOptions.H"
