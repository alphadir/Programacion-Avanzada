package meditor;
import java.awt.*;// se agregan pasos para terminar el proceso
import java.awt.event.*;//  1/5 importar los listeners

public class LEditor implements ActionListener {// 2/5 se implementa interface
	Frame F;
	MenuBar MB;
	Menu MArchivo;
	TextArea TA;
	MenuItem Salir;
	MenuItem Bold;
	public LEditor(){
		F=new Frame("LEditor");
		F.setMenuBar(MB=new MenuBar());
		MB.add(MArchivo=new Menu("Archivo"));
		MArchivo.add(Salir=new MenuItem("Salir"));
		MArchivo.add(Bold= new MenuItem("BoldFace")); //negritas
		Salir.addActionListener(this);// 3/5 se agrega el ecucha
		Bold.addActionListener(this);// paso 3 de negritas
		F.setLayout(new BorderLayout());
		F.add(TA=new TextArea(), BorderLayout.CENTER);
		
		F.addWindowListener(new WindowAdapter(){//para cerrar desde ventana
			public void windowClosing(WindowEvent we){
				F.dispose();// liberar recursos
				System.exit(0);
			}
		});
		
		F.setSize(700,500);
		F.setLocationRelativeTo(null);
		F.setVisible(true);
	}
	
	public void actionPerformed(ActionEvent ae){// 4/5 se implementa el/los metodos de la interface
		if(ae.getActionCommand().equals("Salir")){
			F.dispose();// liberar recursos
			System.exit(0);
		}
		if(ae.getActionCommand().equals("BoldFace")){
			Font f=TA.getFont();
			TA.setFont(new Font(f.getFontName(), Font.BOLD, 20));
		}
	}
	
	public static void main(String arr[]){
		new LEditor();
	}
}

