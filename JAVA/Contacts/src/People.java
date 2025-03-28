public class People {
    private String name;
    private String number;
    private String belonging;
    private String email;   

    public People(String name, String number, String belonging, String email) {
        this.name = name;
        this.number = number;
        this.belonging = belonging;
        this.email = email;
    }

    public String getName() {
        return name;
    }

    public String getNumber() {
        return number;
    }

    public String getBelonging() {
        return belonging;
    }

    public String getEmail() {
        return email;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setNumber(String number) {
        this.number = number;
    }

    public void setBelonging(String belonging) {
        this.belonging = belonging;
    }

    public void setEmail(String email) {
        this.email = email;
    }
}
