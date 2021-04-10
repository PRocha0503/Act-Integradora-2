#ifndef BITACORA_H
#define BITACORA_H
#include <string>
#include <iostream>
using std::string;


struct formatoHora{
    int mes;
    int dia;
    int hora;
    int minuto;
    int segundo;
};

bool operator>(formatoHora hora1,formatoHora hora2){
    if(hora1.mes>hora2.mes){
        return true;
    }
    else if(hora1.mes==hora2.mes){
        if(hora1.dia>hora2.dia){
            return true;
        }
        else if(hora1.dia==hora2.dia){
            if(hora1.hora>hora2.hora){
                return true;
            }
            else if(hora1.hora==hora2.hora){
                if(hora1.minuto>hora2.minuto){
                    return true;
                }
                else if(hora1.minuto==hora2.minuto){
                    if(hora1.segundo>hora2.segundo){
                        return true;
                        }
                }
            }
        }
    }
    return false;
}
bool operator<(formatoHora hora1,formatoHora hora2){
    if(hora1.mes<hora2.mes){
        return true;
    }
    else if(hora1.mes==hora2.mes){
        if(hora1.dia<hora2.dia){
            return true;
        }
        else if(hora1.dia==hora2.dia){
            if(hora1.hora<hora2.hora){
                return true;
            }
            else if(hora1.hora==hora2.hora){
                if(hora1.minuto<hora2.minuto){
                    return true;
                }
                else if(hora1.minuto==hora2.minuto){
                    if(hora1.segundo<hora2.segundo){
                        return true;
                        }
                }
            }
        }
    }
    return false;
}
bool operator==(formatoHora hora1,formatoHora hora2){
    if(hora1.mes==hora2.mes && hora1.dia==hora2.dia&&hora1.hora==hora2.hora&&hora1.minuto==hora2.minuto&&hora1.segundo==hora2.segundo){
        return true;
    }
    return false;
}

bool operator!= (formatoHora hora1,formatoHora hora2){
    if(hora1.mes==hora2.mes && hora1.dia==hora2.dia&&hora1.hora==hora2.hora&&hora1.minuto==hora2.minuto&&hora1.segundo==hora2.segundo){
        return false;
    }
    return true;
}

bool operator>=(formatoHora hora1,formatoHora hora2){
    if(hora1.mes==hora2.mes && hora1.dia==hora2.dia&&hora1.hora==hora2.hora&&hora1.minuto==hora2.minuto&&hora1.segundo==hora2.segundo){
        return true;
    }
    if(hora1.mes>hora2.mes){
        return true;
    }
    else if(hora1.mes==hora2.mes){
        if(hora1.dia>hora2.dia){
            return true;
        }
        else if(hora1.dia==hora2.dia){
            if(hora1.hora>hora2.hora){
                return true;
            }
            else if(hora1.hora==hora2.hora){
                if(hora1.minuto>hora2.minuto){
                    return true;
                }
                else if(hora1.minuto==hora2.minuto){
                    if(hora1.segundo>hora2.segundo){
                        return true;
                        }
                }
            }
        }
    }
    return false;   
}
bool operator<=(formatoHora hora1,formatoHora hora2){
    if(hora1.mes==hora2.mes && hora1.dia==hora2.dia&&hora1.hora==hora2.hora&&hora1.minuto==hora2.minuto&&hora1.segundo==hora2.segundo){
        return true;
    }
    if(hora1.mes<hora2.mes){
        return true;
    }
    else if(hora1.mes==hora2.mes){
        if(hora1.dia<hora2.dia){
            return true;
        }
        else if(hora1.dia==hora2.dia){
            if(hora1.hora<hora2.hora){
                return true;
            }
            else if(hora1.hora==hora2.hora){
                if(hora1.minuto<hora2.minuto){
                    return true;
                }
                else if(hora1.minuto==hora2.minuto){
                    if(hora1.segundo<hora2.segundo){
                        return true;
                        }
                }
            }
        }
    }
    return false;

}

struct entrada{
    formatoHora fecha; 
    string ip;
    string razonFalla;
};

bool operator>(entrada entrada1, entrada entrada2){
    if(entrada1.fecha>entrada2.fecha){
        return true;
    }
    return false;
}

bool operator<(entrada entrada1, entrada entrada2){
    if(entrada1.fecha<entrada2.fecha){
        return true;
    }
    return false;
}
bool operator==(entrada entrada1, entrada entrada2){
    if(entrada1.fecha==entrada2.fecha){
        return true;
    }
    return false;
}
bool operator!=(entrada entrada1, entrada entrada2){
    if(entrada1.fecha!=entrada2.fecha){
        return true;
    }
    return false;
}
bool operator>=(entrada entrada1, entrada entrada2){
    if(entrada1.fecha>=entrada2.fecha){
        return true;
    }
    return false;
}
bool operator<=(entrada entrada1, entrada entrada2){
    if(entrada1.fecha<=entrada2.fecha){
        return true;
    }
    return false;
}
string convertirDeRegreso(int m){
    if(m==1){
        return "Jan";
    }
    else if(m==2){
        return "Feb";
    }
    else if(m==3){
        return "Mar";
    }
    else if(m==4){
        return "Apr";
    }
    else if(m==5){
        return "May";
    }
    else if(m==6){
        return "Jun";
    }
    else if(m==7){
        return "Jul";
    }
    else if(m==8){
        return "Aug";
    }
    else if(m==9){
        return "Sep";
    }
    else if(m==10){
        return "Oct";
    }
    else if(m==11){
        return "Nov";
    }
    else if(m==12){
        return "Dec";
    }
    return "100000";
};
string ceroIzquierda(int num){
    string numString;
    numString = std::to_string(num);
    if(num<10){
        numString = "0"+ numString;
    } 
    return numString;
};

std::ostream& operator<<(std::ostream& os, const entrada& entrada1)
{
    os << convertirDeRegreso(entrada1.fecha.mes)<<" "<<entrada1.fecha.dia<<" "<<ceroIzquierda(entrada1.fecha.hora)<<":"<<ceroIzquierda(entrada1.fecha.minuto)<<":"<<ceroIzquierda(entrada1.fecha.segundo)<<" "<<entrada1.ip<<" "<<entrada1.razonFalla;
    return os;
}

#endif