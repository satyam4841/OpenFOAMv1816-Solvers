					vector cellCentroid = C[cellI];
                    vector X = C[spiralcells[flagCell]];
                    const double x = (cellCentroid.x() - X.x())*(cellCentroid.x() - X.x());
                    const double y = (cellCentroid.y() - X.y())*(cellCentroid.y() - X.y());
                    const double z = (cellCentroid.z() - X.z())*(cellCentroid.z() - X.z());
                    g[cellI]=(3*q.value()/(3.14*r.value()*r.value()*rho.value()*Cp.value()*lambda.value()))*Foam::exp((x+y+z)*(3/(-r.value()*r.value())));