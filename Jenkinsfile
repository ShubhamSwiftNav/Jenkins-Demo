    //Parametrize your Build
    ////// select version of the application you want to deploy .
pipeline {
    agent any
    stages {
        
        stage('init') {
        steps {
        echo 'Pipeline INIT...'
    }}
        stage('build') { 
        steps {
        echo 'building the application...'
        sh 'rm -rf play'
        sh 'mkdir play && cd play && cp -r /home/jangoo/Downloads/Jenkins/Project/Jenkins-Demo/ .'
        sh 'cd play && mkdir build && cd build && cmake ../.. && cmake --build .'
    }}
    stage('test') {
        steps {
            echo 'testing the application...'
            sh "play/build/tst/Factorial_test"
    }}
        stage('Success/Failure') {
            steps {
                catchError(buildResult: 'SUCCESS', stageResult: 'SUCCESS') {
                    sh "exit 1"
                }
            }
        }
}
        post {
            success {
            echo 'Success Mail Body'
            
            emailext body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} Commit id ${env.GIT_COMMIT} Build ${env.BUILD_NUMBER}\n More info at: ${env.BUILD_URL}\n For now you can proceed to third step which is authorization LINK LINK",
            recipientProviders: [[$class: 'RequesterRecipientProvider']],
            subject: "Jenkins Build ${currentBuild.currentResult}: Job ${env.JOB_NAME}"
            }
            failure {
            echo 'Fail Mail Body'
                
            emailext body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} Commit id ${env.GIT_COMMIT} Build ${env.BUILD_NUMBER}\n More info at: ${env.BUILD_URL}\n You cannot proceed to third step because your jenkins has failed please try again",
            recipientProviders: [[$class: 'RequesterRecipientProvider']],
            subject: "Jenkins Build ${currentBuild.currentResult}: Job ${env.JOB_NAME}"
            }
}
}
