from scipy.optimize import minimize
from fastapi import FastAPI

app = FastAPI()

@app.get("/")
def read_root():
    return {"Hello": "World"}

@app.get("/optimize")
def optimize(x1: float, x2: float, x3: float):
    def f(x):
        return x[0]**2 + x[1]**2 + x[2]**2

    cons = ({'type': 'ineq', 'fun': lambda x: x[0] - 2*x[1] + 2*x[2] - 1},
            {'type': 'ineq', 'fun': lambda x: -x[0] + 2*x[1] - 2*x[2] + 1},
            {'type': 'ineq', 'fun': lambda x: x[0] + x[1] + x[2] - 1})

    res = minimize(f, [x1, x2, x3], constraints=cons)

    return {"result": res.x}            
