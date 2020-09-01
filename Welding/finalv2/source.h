                    vector cellCentroid = C[cellI];
                    vector X = C[spiralcells[flagCell]];
                    double Angle = angle(X.x(),X.y());
                    double cellAngle = angle(cellCentroid.x(),cellCentroid.y());
                    double w = angle(X.x(),X.y())/toDegrees;
                    double majAxis = (cellCentroid.x()-X.x())*Foam::cos(w+(pi/2)) + (cellCentroid.y()-X.y())*Foam::sin(w+(pi/2)); // Elipse axis
                    double minAxis = (cellCentroid.x()-X.x())*Foam::sin(w+(pi/2)) - (cellCentroid.y()-X.y())*Foam::cos(w+(pi/2)); // ,,
                    const double x = (majAxis)*(majAxis);
                    const double y = (minAxis)*(minAxis);
                    const double z = (cellCentroid.z() - X.z())*(cellCentroid.z() - X.z());
                    //const double rd = 0;//Foam::sqrt(pow(X.x(),2) + pow(X.y(),2));
                    const double asq = a.value()*a.value();
                    const double bsq = b.value()*b.value();
                    const double cfsq = cf.value()*cf.value();
                    const double crsq = cr.value()*cr.value();
                    const double k = 1.86632412;

                        if(Angle >= 340)
                        {
                            if(cellAngle >= 0 and cellAngle <= 30)
                            {
                                cellAngle = 360 + cellAngle;
                            }
                            if(cellAngle >= Angle) //Forward elipsoid
                            {
                                g[cellI]=((k*ff.value()*q.value())/(a.value()*b.value()*cf.value()*rho.value()*Cp.value()))*Foam::exp(-3*((x/cfsq)+(y/asq)+(z/bsq)));    
                            }
                            if(cellAngle < Angle) //Rear elipsoid
                            {
                                g[cellI]=((k*fr.value()*q.value())/(a.value()*b.value()*cr.value()*rho.value()*Cp.value()))*Foam::exp(-3*((x/crsq)+(y/asq)+(z/bsq)));    
                            }
                        }
                        if(Angle <= 20)
                        {
                            if(cellAngle >= 330 && cellAngle <= 360)
                            {
                                cellAngle = cellAngle - 360;
                            }
                            if(cellAngle >= Angle) //Forward elipsoid
                            {
                                g[cellI]=((k*ff.value()*q.value())/(a.value()*b.value()*cf.value()*rho.value()*Cp.value()))*Foam::exp(-3*((x/cfsq)+(y/asq)+(z/bsq)));    
                            }
                            if(cellAngle < Angle) //Rear elipsoid
                            {
                                g[cellI]=((k*fr.value()*q.value())/(a.value()*b.value()*cr.value()*rho.value()*Cp.value()))*Foam::exp(-3*((x/crsq)+(y/asq)+(z/bsq)));    
                            }
                        }
                        else{
                            if(cellAngle >= Angle) //Forward elipsoid
                            {
                                g[cellI]=((k*ff.value()*q.value())/(a.value()*b.value()*cf.value()*rho.value()*Cp.value()))*Foam::exp(-3*((x/cfsq)+(y/asq)+(z/bsq)));    
                            }
                            if(cellAngle < Angle) //Rear elipsoid
                            {
                                g[cellI]=((k*fr.value()*q.value())/(a.value()*b.value()*cr.value()*rho.value()*Cp.value()))*Foam::exp(-3*((x/crsq)+(y/asq)+(z/bsq)));    
                            }
                        }