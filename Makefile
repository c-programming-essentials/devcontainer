build:
	docker build -t olivierpierre/essential-c-devcontainer .devcontainer

push:
	docker login
	docker push olivierpierre/essential-c-devcontainer