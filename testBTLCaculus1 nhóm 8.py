#BÀi 3:
import sympy as sp

# Khai báo biến
x = sp.Symbol('x', positive=True)

# Đường cong 1: sqrt(1 + 4x^2)
curve_1 = sp.sqrt(1 + 4 * x**2)  # Công thức sqrt(1 + 4x^2)
L1 = sp.integrate(curve_1, (x, 0, 1.587401052))  # Tích phân từ x=0 đến x=1.587401052

# Đường cong 2: sqrt(1 + 1/x)
curve_2 = sp.sqrt(1 + 1 / x)  # Công thức sqrt(1 + 1/x)
L2 = sp.integrate(curve_2, (x, 0.00000001, 1.587401052))  # Tích phân từ x=0.00000001 đến x=1.587401052

# Tổng chu vi
P = L1 + L2
P_rounded = round(P.evalf(), 4)  # Làm tròn đến 4 chữ số thập phân

# In kết quả
print(f"Độ dài đường cong 1: {L1.evalf()}")
print(f"Độ dài đường cong 2: {L2.evalf()}")
print(f"Chu vi miền phẳng (làm tròn): {P_rounded}")
