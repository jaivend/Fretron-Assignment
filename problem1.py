import matplotlib.pyplot as plt

def plot_routes(routes):
    figure,axis=plt.subplots()
    
    for i, route in enumerate(routes):
        x_vals=[point[0] for point in route]
        y_vals=[point[1] for point in route]
        axis.plot(x_vals, y_vals,marker='o',label=f'Route {i+1}')
        for (x, y) in route:
            axis.text(x, y,f'({x},{y})',fontsize=9, ha='right')

    axis.set_xlabel('x coordinate')
    axis.set_ylabel('y coordinate')
    axis.set_title('Routes')
    axis.legend()

    plt.grid(True)
    plt.show()

# Ex input
routes=[
    [(1,1),(2,2),(3,3)],   # 1
    [(1,1),(2,4),(3,2)],   # 2
    [(1,1),(4,2),(3,4)]    # 3
]

plot_routes(routes)
