pipeline {
  agent any

    //Parametrize your Build
    ////// select version of the application you want to ddddddddddddeployyyyy .

  stages {

    stage("init") {
        steps {
        echo 'Pipeline INIT...'
    }}
pipeline {
    agent any
    
    stages {
        stage('Ok') {
            steps {
                echo "Ok"
            }
        }
    }
    post {
        always {
            emailext body: 'A Test EMail', recipientProviders: [[$class: 'DevelopersRecipientProvider'], [$class: 'RequesterRecipientProvider']], subject: 'Test'
        }
    }
}
    stage("deploy") {
        steps {
          echo 'deploying the application...'
        }
    }
  }
}
