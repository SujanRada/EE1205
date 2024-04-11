import sympy as sp

# Define symbols
s, z = sp.symbols('s z')

# Given transfer function
Ha_BP_s = s**4 / (s**8 + 0.13768592*s**7 + 2.34752917103355*s**6 + 0.241599034332001*s**5 + 2.05194314697209*s**4 + 0.14028302969067*s**3 + 0.791463484932473*s**2 + 0.0269537601135888*s + 0.113668406234963)

# Perform substitution
substitution = ((1 - z**-1) / (1 + z**-1))
substituted_expression = Ha_BP_s.subs(s, substitution)

# Simplify the expression
simplified_expression = sp.simplify(substituted_expression)

# Print the result
print("Expression in z:")
print(simplified_expression)


