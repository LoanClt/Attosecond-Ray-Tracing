import numpy as np

final_array = "["
N = 20
theta = np.linspace(0, 2*np.pi, N)
R = 15
for angle in theta:
    x = R*np.cos(angle)
    y = R*np.sin(angle)
    final_array += str(x) + " " + str(y) + " 0 0 0 1;\n"
final_array += "];"

print(final_array)
