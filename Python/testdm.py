import tkinter as tk 
class HerbicidalUpperComputer: 
    def __init__(self): 
        self.root = tk.Tk() 
        self.root.title("除草剂上位机程序") # 参数设置标签和输入框 
        tk.Label(self.root, text="喷洒剂量：").grid(row=0, column=0) 
        self.dose_entry = tk.Entry(self.root) 
        self.dose_entry.grid(row=0, column=1) 
        tk.Label(self.root, text="喷洒速度：").grid(row=1, column=0) 
        self.speed_entry = tk.Entry(self.root) 
        self.speed_entry.grid(row=1, column=1) 
        tk.Label(self.root, text="喷洒范围：").grid(row=2, column=0) 
        self.range_entry = tk.Entry(self.root) 
        self.range_entry.grid(row=2, column=1) # 设备控制按钮 
        self.start_button = tk.Button(self.root, text="启动", command=self.start_spraying) 
        self.start_button.grid(row=3, column=0) 
        self.stop_button = tk.Button(self.root, text="停止", command=self.stop_spraying) 
        self.stop_button.grid(row=3, column=1) # 数据显示区域 
        self.status_label = tk.Label(self.root, text="设备状态：待启动") 
        self.status_label.grid(row=4, column=0, columnspan=2) 
        self.data_label = tk.Label(self.root, text="喷洒数据：暂无") 
        self.data_label.grid(row=5, column=0, columnspan=2) 
        self.is_spraying = False 
        
    def start_spraying(self): 
        dose = self.dose_entry.get() 
        speed = self.speed_entry.get() 
        range_value = self.range_entry.get() # 这里可以添加实际启动设备的代码逻辑，模拟时仅更新状态 
        self.is_spraying = True 
        self.status_label.config(text=f"设备状态：正在喷洒（剂量：{dose}，速度：{speed}，范围：{range_value}）") 
        self.data_label.config(text="喷洒数据：开始记录") 

    def stop_spraying(self): # 这里可以添加实际停止设备的代码逻辑，模拟时仅更新状态 
        self.is_spraying = False 
        self.status_label.config(text="设备状态：已停止") 
        self.data_label.config(text="喷洒数据：停止记录") 

if __name__ == "__main__": 
    app = HerbicidalUpperComputer() 
    app.root.mainloop()