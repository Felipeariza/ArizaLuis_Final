import matplotlib.pyplot as plt
import numpy as np

datos= np.genfromtxt("valores.txt", delimiter = " ")

t = np.linspace(0,10,len(datos))
plt.figure()
plt.plot(datos[0:],t)
#plt.plot(datos[1:],t)
plt.show()
plt.savefig("ArizaLuis_final_p15.pdf")
#print (datos)
