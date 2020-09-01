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

volScalarField Phi // Phase field
(
    IOobject
    (
        "Phi",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

volScalarField Ki // Random Noise field
(
    IOobject
    (
        "Ki",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
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


Info<< "Reading diffusivity DT\n" << endl;

dimensionedScalar DT
(
    "DT",
    dimArea/dimTime,
    transportProperties
);

// Info<< "Reading diffusivity DT\n" << endl;

dimensionedScalar epsilon
(
    "epsilon",
    dimLength,
    transportProperties
);

dimensionedScalar tau
(
    "tau",
    dimTime,
    transportProperties
);

dimensionedScalar alpha
(
    "alpha",
    dimless,
    transportProperties
);

dimensionedScalar gamma
(
    "gamma",
    dimless,
    transportProperties
);

dimensionedScalar a //Noise amplitude
(
    "a",
    dimless,
    transportProperties
);

dimensionedScalar K // Strength of undercooling
(
    "K",
    dimTemperature,
    transportProperties
);

dimensionedScalar Te // Strength of undercooling
(
    "Te",
    dimTemperature,
    transportProperties
);


#include "createFvOptions.H"
