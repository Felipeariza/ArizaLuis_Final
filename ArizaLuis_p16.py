import matplotlib.pyplot as plt
import numpy as np

    b_ini_1=7.5
    b_ini_2=7.5
    b_ini_3=7.5
    b_ini_4=7.5
    b_ini_5=7.5
    b_ini_6=7.5
 
    
    
    b_final1 = []
    b_final2= []
    b_final3 = []
    b_final4 = []
    b_final5 = []
    b_final6 = []
    for i in range(pasos):

        #Se define el f nuevo para obtener el parametro alfa
 

        
        a = random.normal(b_ini_1,sigma)
        
    
        alpha = float(l_nue/l_vie)
        #Se ponen las condiciones para aceptar el alpha
        if alpha >= 1:
            aini = a
                       
            a_final.append(a)
           
        else:
            beta = random.uniform(0,1)
            if beta < alpha:
                b_ini_1 = a
               
                a_final.append(a)
                
                
            else:
                l.append(l_vie)

    mini = min(l)
    ind  = l.index(mini)
    
