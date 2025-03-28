import java.util.Scanner;

public class MyScanner {
    private Scanner in = new Scanner(System.in);

    public int InputInt() {
		while (true) {
			try {
				int t = in.nextInt();
				return t;
			} catch (RuntimeException a) {
				System.out.println("[ " + in.nextLine() + " ] 不是有效的输入");
			}
		}
	}

    public int InputInt(int l, int r) {
		while (true) {
			int t = in.nextInt();
            if (t >= l && t <= r) {
                return t;
            } else {
                System.out.println("请输入 " + l + " 到 " + r + " 之间的数字"); 
            }
		}
	}

    public char InputChar(int l, int r){
		char t;
		while(true) {
			t = in.next().charAt(0);
			if(t >= l && t <= r) {
				return t;
			}else {
				System.out.println("请输入 " + l + " 到 " + r + " 之间的字符");
			}
		}
	}

    public String InputString() {
		String t;
		while(true) {
			try {
				t = in.next();
				return t;
			}catch(RuntimeException a) {
				System.out.println("[ "+in.nextLine()+" ] 不是有效的输入");
			}
		}
	}

    public String InputNumber(){
        String t;
        while(true) {
            t = in.nextLine(); 
            if(t.length() != 11){
                System.out.println("请输入11位的数字");
            }else{
                return t;
            }
        }
    }

    public String InputEmail(){
        String t;
        while(true) {
            t = in.nextLine();
            if(!t.contains("@")){
                System.out.println("请输入正确的邮箱格式");
            }else{
                return t;
            }
        }
    }
}
