CREATE TABLE emitentes (
	id		 SERIAL NOT NULL,
	cnpj		 CHAR(14) NOT NULL,
	razao_social	 VARCHAR(255) NOT NULL,
	nome_fantasia	 VARCHAR(255),
	inscricao_estadual VARCHAR(20),
	PRIMARY KEY(id)
);

CREATE TABLE destinatarios (
	id		 SERIAL NOT NULL,
	cpf_cnpj		 VARCHAR(14) NOT NULL,
	nome_razao_social	 VARCHAR(255) NOT NULL,
	inscricao_estadual VARCHAR(20),
	PRIMARY KEY(id)
);

CREATE TABLE transportadoras (
	id		 SERIAL NOT NULL,
	cnpj_cpf		 VARCHAR(14) NOT NULL,
	razao_social	 VARCHAR(255) NOT NULL,
	inscricao_estadual VARCHAR(20),
	PRIMARY KEY(id)
);

CREATE TABLE enderecos (
	id		 SERIAL NOT NULL,
	emitente_id	 INTEGER,
	destinatario_id	 INTEGER,
	transportadora_id INTEGER,
	logradouro	 VARCHAR(255) NOT NULL,
	numero		 VARCHAR(20),
	complemento	 VARCHAR(100),
	bairro		 VARCHAR(100),
	municipio	 VARCHAR(100) NOT NULL,
	uf		 CHAR(2) NOT NULL,
	cep		 CHAR(8),
	tipo_endereco	 VARCHAR(50) DEFAULT 'comercial',
	destinatarios_id	 INTEGER NOT NULL,
	emitentes_id	 INTEGER NOT NULL,
	PRIMARY KEY(id)
);

CREATE TABLE telefones (
	id		 SERIAL NOT NULL,
	emitente_id	 INTEGER,
	destinatario_id	 INTEGER,
	transportadora_id INTEGER,
	ddd		 CHAR(3),
	numero		 VARCHAR(20) NOT NULL,
	tipo_telefone	 VARCHAR(20) DEFAULT 'comercial',
	destinatarios_id	 INTEGER NOT NULL,
	emitentes_id	 INTEGER NOT NULL,
	PRIMARY KEY(id)
);

CREATE TABLE produtos (
	id		 SERIAL NOT NULL,
	codigo_produto VARCHAR(60) NOT NULL,
	descricao	 VARCHAR(255) NOT NULL,
	ncm_sh	 CHAR(8),
	unidade_padrao VARCHAR(10) NOT NULL DEFAULT 'UN',
	preco_padrao	 DOUBLE PRECISION DEFAULT 0.00,
	PRIMARY KEY(id)
);

CREATE TABLE notas_fiscais (
	id			 SERIAL NOT NULL,
	chave_acesso		 CHAR(44) NOT NULL,
	numero_nota		 VARCHAR(20) NOT NULL,
	serie			 VARCHAR(5) NOT NULL,
	tipo_operacao		 VARCHAR(10) NOT NULL,
	natureza_operacao		 VARCHAR(100) NOT NULL,
	protocolo_autorizacao	 VARCHAR(50),
	data_emissao		 DATE NOT NULL,
	data_saida_entrada	 DATE,
	emitente_id		 INTEGER NOT NULL,
	destinatario_id		 INTEGER NOT NULL,
	transportadora_id		 INTEGER,
	base_calculo_icms		 DOUBLE PRECISION NOT NULL DEFAULT 0.00,
	valor_icms		 DOUBLE PRECISION NOT NULL DEFAULT 0.00,
	base_calculo_icms_st	 DOUBLE PRECISION NOT NULL DEFAULT 0.00,
	valor_icms_st		 DOUBLE PRECISION NOT NULL DEFAULT 0.00,
	valor_total_produtos	 DOUBLE PRECISION NOT NULL DEFAULT 0.00,
	valor_frete		 DOUBLE PRECISION NOT NULL DEFAULT 0.00,
	valor_seguro		 DOUBLE PRECISION NOT NULL DEFAULT 0.00,
	desconto			 DOUBLE PRECISION NOT NULL DEFAULT 0.00,
	outras_despesas		 DOUBLE PRECISION NOT NULL DEFAULT 0.00,
	valor_ipi			 DOUBLE PRECISION NOT NULL DEFAULT 0.00,
	valor_total_nota		 DOUBLE PRECISION NOT NULL DEFAULT 0.00,
	frete_por_conta		 VARCHAR(20) NOT NULL,
	quantidade_volumes	 INTEGER DEFAULT 0,
	especie_volumes		 VARCHAR(50),
	marca_volumes		 VARCHAR(50),
	peso_bruto_kg		 DOUBLE PRECISION DEFAULT 0.00,
	peso_liquido_kg		 DOUBLE PRECISION DEFAULT 0.00,
	informacoes_complementares TEXT,
	destinatarios_id		 INTEGER NOT NULL,
	emitentes_id		 INTEGER NOT NULL,
	PRIMARY KEY(id)
);

CREATE TABLE duplicatas (
	id		 SERIAL NOT NULL,
	nota_fiscal_id	 INTEGER NOT NULL,
	numero_duplicata VARCHAR(20) NOT NULL,
	data_vencimento	 DATE NOT NULL,
	valor		 DOUBLE PRECISION NOT NULL DEFAULT 0.00,
	notas_fiscais_id INTEGER NOT NULL,
	PRIMARY KEY(id)
);

CREATE TABLE itens_nota_fiscal (
	id		 SERIAL NOT NULL,
	nota_fiscal_id	 INTEGER NOT NULL,
	produto_id	 INTEGER NOT NULL,
	cst		 CHAR(3),
	cfop		 CHAR(4) NOT NULL,
	unidade		 VARCHAR(10) NOT NULL,
	quantidade	 DOUBLE PRECISION NOT NULL DEFAULT 0.00,
	valor_unitario	 DOUBLE PRECISION NOT NULL DEFAULT 0.00,
	valor_total	 DOUBLE PRECISION NOT NULL DEFAULT 0.00,
	base_calculo_icms DOUBLE PRECISION DEFAULT 0.00,
	valor_icms	 DOUBLE PRECISION DEFAULT 0.00,
	valor_icms_st	 DOUBLE PRECISION DEFAULT 0.00,
	valor_ipi	 DOUBLE PRECISION DEFAULT 0.00,
	aliquota_icms	 FLOAT DEFAULT 0.00,
	aliquota_ipi	 FLOAT DEFAULT 0.00,
	produtos_id	 INTEGER NOT NULL,
	notas_fiscais_id	 INTEGER NOT NULL,
	PRIMARY KEY(id)
);

CREATE TABLE transportadoras_notas_fiscais (
	transportadoras_id INTEGER NOT NULL,
	notas_fiscais_id	 INTEGER,
	PRIMARY KEY(notas_fiscais_id)
);

ALTER TABLE emitentes ADD UNIQUE (cnpj);
ALTER TABLE destinatarios ADD UNIQUE (cpf_cnpj);
ALTER TABLE transportadoras ADD UNIQUE (cnpj_cpf);
ALTER TABLE enderecos ADD CONSTRAINT enderecos_fk1 FOREIGN KEY (destinatarios_id) REFERENCES destinatarios(id);
ALTER TABLE enderecos ADD CONSTRAINT enderecos_fk2 FOREIGN KEY (emitentes_id) REFERENCES emitentes(id);
ALTER TABLE telefones ADD CONSTRAINT telefones_fk1 FOREIGN KEY (destinatarios_id) REFERENCES destinatarios(id);
ALTER TABLE telefones ADD CONSTRAINT telefones_fk2 FOREIGN KEY (emitentes_id) REFERENCES emitentes(id);
ALTER TABLE produtos ADD UNIQUE (codigo_produto);
ALTER TABLE notas_fiscais ADD UNIQUE (chave_acesso);
ALTER TABLE notas_fiscais ADD CONSTRAINT notas_fiscais_fk1 FOREIGN KEY (destinatarios_id) REFERENCES destinatarios(id);
ALTER TABLE notas_fiscais ADD CONSTRAINT notas_fiscais_fk2 FOREIGN KEY (emitentes_id) REFERENCES emitentes(id);
ALTER TABLE duplicatas ADD CONSTRAINT duplicatas_fk1 FOREIGN KEY (notas_fiscais_id) REFERENCES notas_fiscais(id);
ALTER TABLE itens_nota_fiscal ADD CONSTRAINT itens_nota_fiscal_fk1 FOREIGN KEY (produtos_id) REFERENCES produtos(id);
ALTER TABLE itens_nota_fiscal ADD CONSTRAINT itens_nota_fiscal_fk2 FOREIGN KEY (notas_fiscais_id) REFERENCES notas_fiscais(id);
ALTER TABLE transportadoras_notas_fiscais ADD CONSTRAINT transportadoras_notas_fiscais_fk1 FOREIGN KEY (transportadoras_id) REFERENCES transportadoras(id);
ALTER TABLE transportadoras_notas_fiscais ADD CONSTRAINT transportadoras_notas_fiscais_fk2 FOREIGN KEY (notas_fiscais_id) REFERENCES notas_fiscais(id);
