import numpy as np
import matplotlib.pyplot as plt

# Safe input function to handle expressions
def safe_input(prompt):
    try:
        value = input(prompt)
        value = value.replace("^", "**")  # Replace '^' with '**' for exponentiation
        return float(eval(value))         # Evaluate the expression and convert to float
    except Exception as e:
        print(f"Lỗi: {e}. Vui lòng nhập lại một giá trị hợp lệ!")
        exit(1)

# Function to input coordinates and charges of the point charges
def input_charges(n):
    x = np.zeros(n)
    y = np.zeros(n)
    q = np.zeros(n)

    print("Nhập tọa độ và điện tích của các điện tích điểm:")
    for i in range(n):
        x[i] = safe_input(f"Nhập x{i+1}: ")
        y[i] = safe_input(f"Nhập y{i+1}: ")
        q[i] = safe_input(f"Nhập q{i+1}: ")
    return x, y, q

# Function to input the test charge data
def input_qo():
    xo = safe_input("Nhập xo (m): ")
    yo = safe_input("Nhập yo (m): ")
    qo = safe_input("Nhập qo (Coulomb): ")
    return xo, yo, qo

# Main program starts here
# Input number of point charges
n = int(input("Nhập số điện tích điểm: "))

# Input the coordinates and charges of the point charges
x, y, q = input_charges(n)

# Input the test charge data
xo, yo, qo = input_qo()

# Coulomb constant
k = 9e9

# Calculate distance between point charges and qo
r_qo = np.sqrt((x - xo)**2 + (y - yo)**2)

# Handle division by zero
if np.any(r_qo == 0):
    raise ValueError("Khoảng cách r giữa điện tích và qo bằng 0! Kiểm tra tọa độ các điện tích.")

# Calculate electrostatic force
F = k * qo * q / r_qo**2

# Calculate force components Fx, Fy
Fx = F * (x - xo) / r_qo
Fy = F * (y - yo) / r_qo

# Calculate total force components and magnitude
F_x = np.sum(Fx)
F_y = np.sum(Fy)
F_magnitude = np.hypot(F_x, F_y)

# Print results
print(f"Tổng hợp lực tĩnh điện: |F| = {F_magnitude:.3e} N")
print(f"Thành phần: Fx = {F_x:.3e} N, Fy = {F_y:.3e} N")

# Plot results
plt.figure(figsize=(8, 6))
plt.title("Biểu diễn lực tĩnh điện")
plt.xlabel("x (m)")
plt.ylabel("y (m)")

# Plot point charges
plt.scatter(x, y, color='blue', label="Điện tích điểm q")
plt.scatter(xo, yo, color='red', label="Điện tích qo")

# Plot force vectors
for i in range(n):
    plt.quiver(xo, yo, Fx[i], Fy[i], angles="xy", scale_units="xy", scale=1, color="green")

# Plot total force
plt.quiver(xo, yo, F_x, F_y, angles="xy", scale_units="xy", scale=1, color="red", label="Lực tổng hợp")

# Finalize plot
plt.legend()
plt.grid()
plt.axis("equal")
plt.show()
