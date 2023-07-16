import { useState } from 'react'
import Module from '../../wasm/main'
import './style.css'

const FibonacciSequence = (): JSX.Element => {

  const [sequenceResult, setSequenceResult] = useState('');
  const [nFib, setNFib] = useState(0)

  const getFibSequence = (n: number): void => {
    Module().then( (module: any) => {
      const fib = module.getFibonacciSequence(n)
      setSequenceResult(fib)
    })
  }

  const handleInput = (e: React.ChangeEvent<HTMLInputElement>): void => {
    setNFib(Number(e.target.value))
  }

  const handleOnKeyDown = (e: React.KeyboardEvent<HTMLInputElement>): void => {
    if(e.key === "Enter"){
      getFibSequence(nFib)
    }
  }

  return (
    <div className='fib__container'>
      <h2 className='fib__title'>Fibonacci Sequence</h2>
      <div className='fib__form_content'>
        <h3 className='fib__form_title'>Calculate sequence up to:</h3>
        <input
          type='number'
          value={nFib}
          onChange={handleInput}
          onKeyDown={handleOnKeyDown}
          className='fib__form_input'
        />
        <button className='fib__form_btn' onClick = {() => getFibSequence(nFib)}>Get Sequence</button>
      </div>
      {
        sequenceResult &&
          <div className='fib__sequence'>
            <h3 className='fib__sequence_title'>Sequence Result</h3>
            <p className='fib__sequence_result'>{sequenceResult}</p>
          </div>
      }
    </div>
  )
}
export default FibonacciSequence;
