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
            
            emailext 
            recipientProviders: [[$class: 'RequesterRecipientProvider']]
            subject: "Jenkins Build ${currentBuild.currentResult}: Job ${env.JOB_NAME}"
            body:'''<a href="${BUILD_URL}input">click to approve</a>''' "${currentBuild.currentResult}: Job ${env.JOB_NAME} Commit id ${env.GIT_COMMIT} Build ${env.BUILD_NUMBER}\n More info at: ${env.BUILD_URL}"
                script{
    
                def userInput = input id: 'userInput',
                              message: 'Let\'s promote?', 
                              submitterParameter: 'submitter',
                              submitter: 'shubham',
                              parameters: [
                                [$class: 'TextParameterDefinition', defaultValue: 'sit', description: 'Environment', name: 'env'],
                                [$class: 'TextParameterDefinition', defaultValue: 'k8s', description: 'Target', name: 'target']]
            echo ("Env: "+userInput['env'])
            echo ("Target: "+userInput['target'])
            echo ("submitted by: "+userInput['submitter'])
            }
            }

            failure {
            echo 'Fail Mail Body'
                
            emailext body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} Commit id ${env.GIT_COMMIT} Build ${env.BUILD_NUMBER}\n More info at: ${env.BUILD_URL}\n You cannot proceed to third step because your jenkins has failed please try again",
            recipientProviders: [[$class: 'RequesterRecipientProvider']],
            subject: "Jenkins Build ${currentBuild.currentResult}: Job ${env.JOB_NAME}"
            }
}
}
