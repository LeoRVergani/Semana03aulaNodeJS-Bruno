// Objeto Simples

let usuario: {
  nome: string;
  idade: number;
  senha: string;
  email: string;
  ativo: boolean;
} = {
  nome: "Carlos",
  idade: 30,
  senha: "1234",
  email: "verga@vergas.com.br",
  ativo: true,
};

// exercicios

const livro: {
  titulo: string;
  autor: string;
  anoPublicacao: number;
  categorias: string[];
  disponivel: boolean;
} = {
  titulo: "Livro 1888",
  autor: "Não sei",
  anoPublicacao: 1888,
  categorias: ["Ficção"],
  disponivel: true,
};

// aula02

function saudacao(nome: string): string {
  return `Olá, ${nome}! Seja bem-vindo!`;
}

const resultado = saudacao("Bruno");

console.log(resultado);

// sem retorno

function mensagem(): void {
  console.log("A aula 2, começou hoje.");
}

mensagem();

// Enum

enum Status {
  Novo = "Nova Tarefa", // 0
  EmAndamento = "Tarefa em Andamento", // 1
  Bloqueado = "Tarefa Bloqueada", // 2
  EmRevisao = "Tarefa em Revisão", // 3
  Concluido = "Tarefa Concluida", // 4
}

let statusAtual = Status.Novo;

console.log(statusAtual);
