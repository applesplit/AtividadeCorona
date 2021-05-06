/*
||CORONA APP || - GRUPO C
Programa para A7 - Do modelo para o Codigo de SI304A_2021S1.
Professor Plinio Vilela

IMPORTANTE: Este programa utiliza 4 arquivos .txt listados abaixo.
Esses arquivos serao criados ao executar o programa.

	- cadadastros.txt
	- mensagens.txt
	- visitas.txt
	- temp.txt (será deletado automaticamente)
	
IMPORTANTE 2: Para ter acesso como Equipe Medica digite "acessoEquipe" na pagina inicial.

IMPORTANTE 3: Cada sintoma possui um NUMERO correspondente a ele. Ver lista na pagina inicial.
	
	- Nao colocar espaco entre as virgulas ao listar os numeros no cadastro.
	- Teoricamente voce nao precisa utilizar os numeros, no entanto, os sintomas devem ser escritos
	todos juntos. Ou seja, sem espaco em nenhum lugar. Exemplo: "dorDeCabeca,dor_de_garganta,febre[ENTER]"
	
Comandos Pagina Inicial:

	- "cadastro": O paciente podera se cadastrar caso seu CPF ainda nao esteja no sistema.
	OBS: Evite colocar espacos no cadastro.
	- "login": O paciente podera fazer o login caso esteja cadastrado.
	- "acessoEquipe": Dara acesso a pagina reservada a equipe medica.
	- "exit": Finaliza o programa.
	
Comandos Paciente (ao fazer login):

	- "verCadastro": O paciente podera ver seus dados de cadastro. (sem senha)
	- "enviarMensagem": O paciente podera enviar uma mensagem a equipe medica.
	- "verMensagens": O paciente podera ver as mensagens enviadas e recebidas da equipe medica.
	- "verRelatorioVisita": O paciente podera ver o relatorio da visita.
	- "logout": Voltara para a pagina principal.
	
Comandos Equipe Medica (ao digitar "acessoEquipe"):

	- "listarCadastros": Listar todos os cadastros dos pacientes no sistema.
	- "filtrarCidade": Filtra os cadastros por cidade.
	- "filtrarEstado": Filtra os cadastros por estado.
	- "filrarSintoma": Filtra os cadastros por sintoma.
	- "enviarMensagem": Envia mensagem a dado paciente.
	- "mensagensComPaciente": Visualiza troca de mensagens com dado paciente.
	- "listarMensagensPacientes": Visualiza todas as mensagens de todos os pacientes.
	- "relatarVisita": Relata visita de certo paciente ao sistema.
	- "totalInfectados": Da o numero total de pacientes infectados por Covid-19 no sistema.
	- "exit": Volta para a pagina inicial.
*/
#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>

using namespace std ;

fstream myfile, myfile2, myfile3, tempfile;

class Paciente {

    private:
	      
        string nome;
    	string telefone;
    	string CPF;
    	string cidade;
    	string estado;
    	string sintomas;
    	string senha;
    	
    public:
    
        void cadastrar(){
        	
			bool flag=0;
			string junk;
        	
        	getline(cin, junk);
        	cout << "Digite o seu nome:" << endl;
			getline(cin, nome);
            
			cout << "Digite o seu telefone:" << endl;
			getline(cin, telefone);
		
			cout << "Digite o seu CPF (sem espaco):" << endl;
			getline(cin, CPF);
		
			cout << "Digite sua cidade (sem espaco):" << endl;
			getline(cin, cidade);
			
			cout << "Digite seu estado (sem espaco):" << endl;
			getline(cin, estado);
		
			cout << "Digite o NUMERO correspondente aos seus sintomas de acordo com a lista acima, separado por virgulas (sem espaco):" << endl;
			getline(cin, sintomas);
			
			cout << "Digite sua senha (sem espaco):" << endl;
			getline(cin, senha);
			
			cout <<  endl;
			cout << "----------------------------------------------" << endl;
			cout <<  endl;
			
			myfile.open("cadastros.txt", ios::in);
			string text;
			
			while(!myfile.eof()){
				getline (myfile, text);
				getline (myfile, text);
				getline (myfile, text);
				if(text == CPF){
					cout << "Este CPF ja esta cadastrado!" << endl;
					cout << endl;
					cout << "----------------------------------------------" << endl;
					cout <<  endl;
					myfile.close();
					flag = 1;
					break;
				}
				getline (myfile, text);
				getline (myfile, text);
				getline (myfile, text);
				getline (myfile, text);
			}
			myfile.close();
            
            if(flag == 0){
            	myfile.open("cadastros.txt", ios::app);
            	myfile << nome << endl;
            	myfile << telefone << endl;
            	myfile << CPF << endl;
            	myfile << cidade << endl;
            	myfile << estado << endl;
            	myfile << sintomas << endl;
            	myfile << senha << endl;
            	myfile.close();
            	cout << "Cadastro feito com sucesso!" << endl;
            	cout <<  endl;
				cout << "----------------------------------------------" << endl;
				cout <<  endl;
			}
		}
		
		bool login(string c, string p){
			bool flag=0;
	        myfile.open("cadastros.txt", ios::in);
	        string text, junk;
	        
			while(!myfile.eof()){
				
				getline (myfile, text);
				getline (myfile, text);
				getline (myfile, text); //linha do cpf
				if(c == text){
					flag = 1;
					getline (myfile, text);
					getline (myfile, text);
					getline (myfile, text);
					getline (myfile, text); //linha da senha
					if(p == text){
						myfile.close();
						return 1;
					}
					else{
						cout << "------------------------------------------------------------" << endl;
						cout << "Senha incorreta." << endl;
						cout << "Digite login novamente para logar." << endl;
						cout << "------------------------------------------------------------" << endl;
						myfile.close();
						return 0;
					}
				}
				else{
				getline (myfile, text);
				getline (myfile, text);
				getline (myfile, text);
				getline (myfile, text);
				}
			}
			
			if(flag == 0){
				cout << "------------------------------------------------------------" << endl;
				cout << "Voce nao esta cadastrado." << endl;
				cout << "------------------------------------------------------------" << endl;
				myfile.close(); 
				return 0;
			}    
	    }
	    
	    void verCadastro(string cpf){
	    	string text, junk;
	    	myfile.open("cadastros.txt", ios::in);
	    	
	    	cout << endl;
	    	cout << "--------------CADASTRO--------------" << endl;
	    	cout << endl;
			while(!myfile.eof()){
					
				tempfile.open("temp.txt", ios::out);
					
				getline (myfile, junk);
				tempfile << junk << endl;
	  			getline (myfile, junk);
	  			tempfile << junk << endl;
	  			
	  			getline (myfile, text);
	  			if(text == cpf){
	  				tempfile.close();
					tempfile.open("temp.txt", ios::in);
		
					getline (tempfile, junk);
					cout << "Nome: " << junk << endl;
		
					getline (tempfile, junk);
					cout << "Telefone: " << junk << endl;
	
					cout << "CPF: " << text << endl;
					
					getline (myfile, text);
	  				cout << "Cidade: " << text << endl;

	  				getline (myfile, text);
	  				cout << "Estado: " << text << endl;

	  				getline (myfile, text);
	  				cout << "Sintomas: " << text << endl;

	  				getline (myfile, text); // senha skip
	  				text = "mateusy184125"; // caso a senha seja igual ao cpf
	  				cout << endl;
	
					tempfile.close();	
				}
				else{
					getline (myfile, text);
					getline (myfile, text);
					getline (myfile, text);
					getline (myfile, text);
					tempfile.close();
				}
			}
			cout << "------------------------------------" << endl;
			cout << endl;
			
	    	myfile.close();
	    	tempfile.close();
	    	remove("temp.txt");
		}
	    
	    void enviarMensagemPaciente(string cpf){
	    	string mensagem;
	    	string junk;
	    	
	    	getline(cin, junk);
	    	cout<<"Envie sua mensagem para a equipe medica:"<<endl; 
	    	getline(cin, mensagem);
	    	
	    	myfile2.open("mensagens.txt", ios::app);
	    	myfile2 << cpf << endl;
	    	myfile2 << "Paciente: "<< mensagem << endl;
	    	cout<<"Mensagem envidada."<<endl;
	    	cout<<endl;
	    	myfile2.close();
		}
		
		void verMensagemPaciente(string cpf) {
			myfile2.open("mensagens.txt", ios::in);
			string text;
			
			cout<<  endl;
			cout << "----------Inicio mensagens---------- " << endl;
			cout<<  endl;
			while(getline(myfile2, text)){
				
				if(text == cpf){
					getline(myfile2, text);
					cout<< text << endl;
					text = "mateusy184125";
					cout<<  endl;	
				}
			}
			cout << "-----------Fim mensagens----------- " << endl;
			cout<<  endl;
			myfile2.close();
		}
};

class Equipe { 

	private:
		
		string acessoEspecial;

    public:
    	
    	void setAcessoEspecial(string acesso){
    		acessoEspecial = acesso;
		}
		
		string getAcessoEspecial(){
    		return acessoEspecial;
		}
    	
    	void listarCadastros(){
    		cout << endl;
    		cout << "----------Inicio lista---------- " << endl;
    		cout << endl;
    		myfile.open("cadastros.txt", ios::in);
    		string text;
    		
    		while(getline (myfile, text)){
    			
  				cout << "Nome: " << text << endl;
  				getline (myfile, text);
  				cout << "Telefone: " << text << endl;
  				getline (myfile, text);
  				cout << "CPF: " << text << endl;
  				getline (myfile, text);
  				cout << "Cidade: " << text << endl;
  				getline (myfile, text);
  				cout << "Estado: " << text << endl;
  				getline (myfile, text);
  				cout << "Sintomas: " << text << endl;
  				getline (myfile, text);
  				cout << endl;
  				
			}
    		myfile.close();
    		cout << "----------Fim lista---------- " << endl;
    		cout << endl;
		}
		
		void filtrarCidade(){
			string cid;
			cout << "Digite o nome da Cidade que gostaria de filtrar: " << endl;
			cin >> cid;
			cout << endl;
					
			cout << endl;
			cout << "----------Inicio filtro---------- "<< endl;
			cout << endl;
			
			myfile.open("cadastros.txt", ios::in);
			string text, junk;
			
				while(!myfile.eof()){
					
					tempfile.open("temp.txt", ios::out);
					
					getline (myfile, junk);
					tempfile << junk << endl;
	  				getline (myfile, junk);
	  				tempfile << junk << endl;
	  				getline (myfile, junk);
	  				tempfile << junk << endl;
	  				
	  				getline (myfile, text);
	  				if(text == cid){
	  					tempfile.close();
						tempfile.open("temp.txt", ios::in);
						
						getline (tempfile, junk);
						cout << "Nome: " << junk << endl;
						
						getline (tempfile, junk);
						cout << "Telefone: " << junk << endl;
						
						getline (tempfile, junk);
						cout << "CPF: " << junk << endl;
						
	  					cout << "Cidade: " << text << endl;
	  					
	  					getline (myfile, text);
	  					cout << "Estado: " << text << endl;
	  					
	  					getline (myfile, text);
	  					cout << "Sintomas: " << text << endl;
	  					
	  					getline (myfile, text); // senha skip
	  					text = "mateusy184125"; // caso a senha seja igual a cidade
	  					cout << endl;
						
						tempfile.close();	
					}
					else{
						getline (myfile, text);
						getline (myfile, text);
						getline (myfile, text);
						tempfile.close();
					}
				}
	    	myfile.close();
	    	tempfile.close();
	    	remove("temp.txt");
	    	cout << "----------Fim filtro---------- "  << endl;
	    	cout << endl;
		}
		
		void filtrarEstado(){
			
			string est;
			cout << "Digite o nome do Estado que gostaria de filtrar: " << endl;
			cin >> est;
			cout << endl;
					
			cout << endl;
			cout << "----------Inicio filtro---------- " << endl;
			cout << endl;
			
			myfile.open("cadastros.txt", ios::in);
			string text, junk;
			
				while(!myfile.eof()){
					
					tempfile.open("temp.txt", ios::out);
					
					getline (myfile, junk);
					tempfile << junk << endl;
	  				getline (myfile, junk);
	  				tempfile << junk << endl;
	  				getline (myfile, junk);
	  				tempfile << junk << endl;
	  				getline (myfile, junk);
	  				tempfile << junk << endl;
	  				
	  				getline (myfile, text);
	  				if(text == est){
	  					tempfile.close();
						tempfile.open("temp.txt", ios::in);
						
						getline (tempfile, junk);
						cout << "Nome: " << junk << endl;
						
						getline (tempfile, junk);
						cout << "Telefone: " << junk << endl;
						
						getline (tempfile, junk);
						cout << "CPF: " << junk << endl;
						
						getline (tempfile, junk);
	  					cout << "Cidade: " << junk << endl;
	  					
	  					cout << "Estado: " << text << endl;
	  					
	  					getline (myfile, text);
	  					cout << "Sintomas: " << text << endl;
	  					
	  					getline (myfile, text); // senha skip
	  					text = "mateusy184125"; // caso a senha seja igual ao estado
	  					cout << endl;
						
						tempfile.close();	
					}
					else{
						getline (myfile, text);
						getline (myfile, text);
						tempfile.close();
					}
				}
	    	myfile.close();
	    	tempfile.close();
	    	remove("temp.txt");
	    	cout << "----------Fim filtro---------- " << endl;
	    	cout << endl;
		}
		
		void filtrarSintoma(){
			
			string sint;
			cout << "Digite o NUMERO do sintoma que gostaria de filtrar: " << endl;
			cin >> sint;
			cout << endl;
			
			cout << endl;
			cout << "----------Inicio filtro---------- "<< endl;
			cout << endl;
			
			myfile.open("cadastros.txt", ios::in);
			string text, junk;
			
				while(!myfile.eof()){
					
					bool flag = 0;
					tempfile.open("temp.txt", ios::out);
					
					getline (myfile, junk);
					tempfile << junk << endl;
	  				getline (myfile, junk);
	  				tempfile << junk << endl;
	  				getline (myfile, junk);
	  				tempfile << junk << endl;
	  				getline (myfile, junk);
	  				tempfile << junk << endl;
	  				getline (myfile, junk);
	  				tempfile << junk << endl;
	  				
	  				getline (myfile, junk);
	  				tempfile << junk << endl;
	  				stringstream   linestream(junk);
    				string   value;
	  				while(getline(linestream,value,',')){  //
	  					if(value == sint)
	  						flag = 1;
					}
	  				
	  				if(flag == 1){
	  					tempfile.close();
						tempfile.open("temp.txt", ios::in);
						
						getline (tempfile, junk);
						cout << "Nome: " << junk << endl;
						
						getline (tempfile, junk);
						cout << "Telefone: " << junk << endl;
						
						getline (tempfile, junk);
						cout << "CPF: " << junk << endl;
						
						getline (tempfile, junk);
	  					cout << "Cidade: " << junk << endl;
	  					
	  					getline (tempfile, junk);
	  					cout << "Estado: " << junk << endl;
	  					
	  					getline (tempfile, junk);
	  					cout << "Sintomas: " << junk << endl;
	  					
	  					getline (myfile, text); // senha skip
	  					text = "mateusy184125"; // caso a senha seja igual ao sintoma
	  					cout << endl;
						
						tempfile.close();	
					}
					else{
						getline (myfile, text);
						text = "blank9371";
						tempfile.close();
					}
				}
	    	myfile.close();
	    	tempfile.close();
	    	remove("temp.txt");
	    	cout << "----------Fim filtro---------- " << endl;
	    	cout << endl;
		}
		
		void enviarMensagemEquipe(){
			string cpf;
	    	string mensagem;
	    	bool flag = 0;
	    	string text, junk;
	    	
	    	getline(cin, junk);
	    	cout<<"Digite o CPF do paciente que gostaria de enviar uma mensagem:"<<endl; 
	    	getline(cin, cpf);
	    	
	    	myfile.open("cadastros.txt", ios::in);
			while(!myfile.eof()){
				getline (myfile, text);
				getline (myfile, text);
				getline (myfile, text);
				if(text == cpf){
					myfile.close();
					flag = 1;
					break;
				}
				getline (myfile, text);
				getline (myfile, text);
				getline (myfile, text);
				getline (myfile, text);
			}
			myfile.close();
			
			if(flag == 0){
				cout << "------------------------------------------------------ " << endl;
            	cout << "Este CPF nao esta cadastrado!" << endl;
            	cout << "Digite enviarMensagem novamente para enviar mensagem." << endl;
            	cout << "------------------------------------------------------ " << endl;
			}
			else{
				cout<<"Envie sua mensagem para o paciente de cpf "<< cpf << ":" <<endl; 
	    		getline(cin, mensagem);
	    	
	    		myfile2.open("mensagens.txt", ios::app);
	    		myfile2 << cpf << endl;
	    		myfile2 << "Equipe Medica: " << mensagem << endl;
	    		cout<<"Mensagem envidada."<<endl;
	    		cout<<endl;
	    		myfile2.close();
			}
		}
		
		void filtrarMensagens() {
			string cpf;
			string text, junk;
			
			getline(cin, junk);
	    	cout<<"Digite o CPF do paciente que gostaria de ver mensagens:"<<endl; 
	    	getline(cin, cpf);
			
			myfile2.open("mensagens.txt", ios::in);
			
			cout << endl;
			cout << "----------Inicio mensagens---------- " << endl;
			cout << endl;
			while(getline(myfile2, text)){
				
				if(text == cpf){
					getline(myfile2, text);
					cout<< text << endl;
					cout<<  endl;	
				}
			}
			cout << "-----------Fim mensagens----------- " << endl;
			cout << endl;
			myfile2.close();
		}
		
		void verMensagens() {
			string text, junk;
		
			
			myfile2.open("mensagens.txt", ios::in);
			
			cout << endl;
			cout << "----------Inicio mensagens---------- " << endl;
			cout << endl;
			while(getline(myfile2, text)){
				
				junk = text;
				getline(myfile2, text);
				if(text[0]=='P'){
					
					cout << "CPF do Paciente: " << junk << endl;
					cout << "Mensagem: " << text.substr(10) << endl;
					cout <<  endl;
				}
			}
			cout << "-----------Fim mensagens----------- " << endl;
			cout << endl;
			myfile2.close();
		}
};

class Visita {
	private:
	 	string data;
		string horario;
		string lugar;
		string descricao;
		string resultado;
	
	public:
		
		void relatarVisita(){
			string cpf, text, junk;
			bool flag = 0;
			
			getline(cin, junk);
        	cout << "Digite o CPF do paciente:" << endl;
        	getline(cin, cpf);
    
			
			myfile.open("cadastros.txt", ios::in);
			while(!myfile.eof()){
				getline (myfile, text);
				getline (myfile, text);
				getline (myfile, text);
				if(text == cpf){
					myfile.close();
					myfile3.open("visitas.txt", ios::app);
					myfile3 << cpf << endl;
					myfile3.close();
					flag = 1;
					break;
				}
				getline (myfile, text);
				getline (myfile, text);
				getline (myfile, text);
				getline (myfile, text);
			}
			myfile.close();
			
			if(flag == 0){
				cout << "------------------------------------------------------ " << endl;
            	cout << "Este CPF nao esta cadastrado!" << endl;
            	cout << "Digite relatarVisita novamente para relatar a visita." << endl;
            	cout << "------------------------------------------------------ " << endl;
			}
			else{
				cout << "Digite a data da visita:" << endl;
				getline(cin, data);
            
				cout << "Digite o horario da visita:" << endl;
				getline(cin, horario);
			
				cout << "Digite o lugar da visita:" << endl;
				getline(cin, lugar);
			
				cout << "Descricao da visita:" << endl;
				getline(cin, descricao);
				
				cout << "Infeccao por COVID-19: (Positivo ou Negativo):" << endl;
				getline(cin, resultado);
				
				myfile3.open("visitas.txt", ios::app);
	            myfile3 << data << endl;
	            myfile3 << horario << endl;
	            myfile3 << lugar << endl;
	            myfile3 << descricao << endl;
	            myfile3 << resultado << endl;
	            myfile3.close();
	            cout << "----------------------------------------------" << endl;
	            cout <<  endl;
	            cout << "Visita relatada ao sistema." << endl;
	            cout <<  endl;
				cout << "----------------------------------------------" << endl;
		
			}
		}
		
		void verRelatorioVisita(string cpf){
			string text;
			bool flag = 0;
			
			myfile3.open("visitas.txt", ios::in);
			while(getline (myfile3, text)){
				
				if(text == cpf){
					flag = 1;
					
					cout << endl;
					cout << "--------RELATORIO DE VISITA--------" << endl;
					cout << endl;
					cout << "O senhor(a), dententor(a) do CPF " << cpf <<", ";

					getline (myfile3, text);
					cout << "visitou nossa equipe medica no dia " << text <<" ";

					getline (myfile3, text);
					cout << "as " << text;
	
					getline (myfile3, text);
		  			cout << " no(a) " << text << "." << endl;
		  			
					
					getline (myfile3, text);
		  			cout << "Descricao da visita: " << text << endl;
				  	
		  			getline (myfile3, text);
		  			cout << "Infeccao pelo COVID-19: " << text << endl;
		  			
		  			cout << endl;
		  			cout << "-----------------------------------" << endl;
		  			cout << endl;
				}
				else{
					getline (myfile3, text);
					getline (myfile3, text);
					getline (myfile3, text);
					getline (myfile3, text);
					getline (myfile3, text);

				}
			}
			myfile3.close();
			if (flag==0){
				cout << endl;
				cout << "-----------------------------------" << endl;
				cout << "Voce ainda nao realizou sua visita." << endl;
				cout << "-----------------------------------" << endl;
				cout << endl;
			}
		}
		
		void totalPositivo(){
			string text;
			int count=0;
			
			myfile3.open("visitas.txt", ios::in);
			while(getline (myfile3, text)){
				
				getline (myfile3, text);
				getline (myfile3, text);
				getline (myfile3, text);
				getline (myfile3, text);
				getline (myfile3, text);
				
				if(text == "Positivo" || text == "positivo"){
					count+=1;
				}
			}
			cout << endl;
			cout << "------------------------------------------------" << endl;
			cout << "Total de pacientes infectados pelo COVID-19: " << count << endl;
			cout << "------------------------------------------------" << endl;
			cout << endl;
			
			myfile3.close();
		}
};

void listar(){
	cout << "Sintomas mais comuns:" << endl;
	cout << "   1) febre" << endl;
	cout << "   2) tosse seca" << endl;
	cout << "   3) cansaco" << endl;
	cout << endl;
	cout << "Sintomas menos comuns:" << endl;
	cout << "   4) dores e desconfortos" << endl;
	cout << "   5) dor de garganta" << endl;
	cout << "   6) diarreia" << endl;
	cout << "   7) conjuntivite" << endl;
	cout << "   8) perda de paladar ou olfato" << endl;
	cout << "   9) erupcao cutanea na pele ou descoloracao dos dedos das maos ou dos pes" << endl;
	cout << endl;
	cout << "Sintomas graves:" << endl;
	cout << "   10) dificuldade de respirar ou falta de ar" << endl;
	cout << "   11) dor ou pressao no peito" << endl;
	cout << "   12) perda de fala ou movimento" << endl;
	cout << endl;
	cout << endl;
	cout << "Caso tenha algum desses sintomas, digite cadastro ou login." << endl;
	cout << "------------------------------------------------------------" << endl;
}

int main(){
	string command, commandIni;
	Paciente p;
	Equipe e;
	Visita v;
	
	myfile.open("cadastros.txt", ios::app);
	if (!myfile) {
		cout << "Erro: Arquivo de cadastros nao foi criado!" << endl;
	}
	myfile.close();
	
	myfile2.open("mensagens.txt", ios::app);
	if (!myfile2) {
		cout << "Erro: Arquivo de mensagens nao foi criado!" << endl;
	}
	myfile2.close();
	
	myfile3.open("visitas.txt", ios::app);
	if (!myfile3) {
		cout << "Erro: Arquivo de visitas nao foi criado!" << endl;
	}
	myfile3.close();
	
	e.setAcessoEspecial("acessoEquipe"); // codigo do acesso Especial
	
	cout<< "|---CORONA APP---|"  << endl;
	cout<< "Veja abaixo alguns dos principais sintomas do COVID-19." << endl;
	cout<< endl;
	listar();
	
	
	while(commandIni!="exit"){
		
		cout << "Faca o cadastro ou o login:" << endl;
		cin >> commandIni;
		
		if (commandIni == "login"){
			string cpf;
			string pass;
			
			cout << "Digite seu CPF: "<< endl;
			cin >> cpf;
			cout << "Digite sua senha: "<< endl;
			cin >> pass;
			if (p.login(cpf, pass) == 1){
				cout << endl;
				cout << "------------------------------------------------------------" << endl;
				cout << "Voce esta logado com o CPF " << cpf << "." <<endl;
				cout << "Comandos disponiveis: verCadastro, enviarMensagem, verMensagens, verRelatorioVisita, logout (voltara para pagina inicial)." << endl;
				cout << "------------------------------------------------------------" << endl;
				cout << endl;
				
				while (command != "logout" ){
					cin >> command;
					
					if(command == "verCadastro"){
						p.verCadastro(cpf);
					}
					
					if(command == "enviarMensagem"){
						p.enviarMensagemPaciente(cpf);
					}
					
					if(command == "verMensagens"){
						p.verMensagemPaciente(cpf);
					}
					
					if(command == "verRelatorioVisita"){
						v.verRelatorioVisita(cpf);
					}
				}
			command="blank184125";  // caso der logout em uma conta e quiser logar de novo.
			}
		}
		
		if (commandIni == "cadastro"){
			p.cadastrar();
		}
		
		
		if (commandIni == e.getAcessoEspecial() ){
			
			cout << endl;
			cout << "------------------------------------------------------------" << endl;
			cout << "Voce acessou como Equipe." << endl;
			cout << "Comandos disponiveis: listarCadastros, filtrarCidade, filtrarEstado, filtrarSintoma, enviarMensagem, ";
			cout << "mensagensComPaciente, listarMensagensPacientes, relatarVisita, totalInfectados, exit (voltar para pagina ininicial) " << endl;
			cout << "------------------------------------------------------------" << endl;
			cout << endl;
			
			while (command != "exit" ){
				
				cin >> command;
				
				if (command == "listarCadastros"){
					e.listarCadastros();
				}
				
				if (command == "filtrarCidade"){
					e.filtrarCidade();
				}
				
				if (command == "filtrarEstado"){
					e.filtrarEstado();
				}
				
				if (command == "filtrarSintoma"){
					e.filtrarSintoma();
				}
				
				if (command == "enviarMensagem"){
					e.enviarMensagemEquipe();
				}
				
				if (command == "mensagensComPaciente"){
					e.filtrarMensagens();
				}
				
				if (command == "listarMensagensPacientes"){
					e.verMensagens();
				}
				
				if (command == "relatarVisita"){
					v.relatarVisita();
				}
				
				if (command == "totalInfectados"){
					v.totalPositivo();
				}
			}
		command="blank184125";  // caso der exit e querer entrar de novo.	
		}
	}
}	
